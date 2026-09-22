#!/bin/sh
set -e

# 1. Setup a completely isolated throwaway workspace
TEST_DIR=$(mktemp -d -t qmd-smoke-XXXXXX)
export XDG_CONFIG_HOME="${TEST_DIR}/config"
export XDG_CACHE_HOME="${TEST_DIR}/cache"

echo "Running qmd smoke test in: ${TEST_DIR}"

# 2. Drop mock text files strictly inside the sandbox
MOCK_DOCS="${TEST_DIR}/docs"
mkdir -p "${MOCK_DOCS}"

cat << 'EOF' > "${MOCK_DOCS}/freebsd_install.md"
---
qmd:
  metadata:
    status: stable
---
# FreeBSD Installation Guide
This document details how to install FreeBSD on modern amd64 architecture.
Make sure to partition your drive using ZFS for optimal stability.
EOF

# 3. CD into the isolated space to prevent project-local leakage
cd "${TEST_DIR}"

# 4. Execute the pipeline
qmd init
qmd collection add "./docs" --name handbook
qmd update

echo "=== Test 1: Full-Text Keyword Search ==="
qmd search "ZFS" --format json

# 5. Clean up environment
rm -rf "${TEST_DIR}"
echo "Smoke test finished successfully!"

