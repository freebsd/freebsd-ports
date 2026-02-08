#! /bin/sh

PATH=/bin:/usr/bin:/usr/local/bin

GIT_CMD="git"
PATCH_CMD="${GIT_CMD} apply"
#PATCH_FLAGS="--numstat --check" # for debugging
PATCH_FLAGS="--verbose --reject"

WRKSRC=$1
PATCH_CONF=${WRKSRC}/electron/patches/config.json

${GIT_CMD} status "${WRKSRC}" > /dev/null 2>&1 && IS_GIT_REPO=1

PATCHD_REPOD_PAIRS=$(jq -r '.[] | .patch_dir + ":" + .repo' "${PATCH_CONF}")
for prp in ${PATCHD_REPOD_PAIRS}; do
    pd=$(echo "${prp}" | awk -F: '{print $1}' | sed -e 's/src/./')
    rd=$(echo "${prp}" | awk -F: '{print $2}' | sed -e 's/src/./')
    (cd "${WRKSRC}/${rd}" && \
         if [ -n "${IS_GIT_REPO}" ]; then
             PATCH_FLAGS="${PATCH_FLAGS} --directory=$(${GIT_CMD} rev-parse --show-prefix)"
         fi && \
         while read -r p; do
             ${PATCH_CMD} ${PATCH_FLAGS} "${WRKSRC}/${pd}/${p}"
         done < "${WRKSRC}/${pd}/.patches")
done
