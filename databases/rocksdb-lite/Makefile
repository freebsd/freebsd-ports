# Created by: David Thiel <lx@FreeBSD.org>

PORTREVISION=	0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Persistent key-value store for fast storage environments (lite version)

LITE=		yes
MASTERDIR=	${.CURDIR}/../rocksdb

BROKEN_armv6=	does not build: db/compaction_job.cc:714:52: error: implicit conversion loses integer precision: 'uint64_t' (aka 'unsigned long long') to 'const size_t' (aka 'const unsigned int')
BROKEN_armv7=	does not build: db/compaction_job.cc:714:52: error: implicit conversion loses integer precision: 'uint64_t' (aka 'unsigned long long') to 'const size_t' (aka 'const unsigned int')
BROKEN_i386=	does not build: tools/db_bench_tool.cc:6320:25: error: non-constant-expression cannot be narrowed from type 'uint64_t' (aka 'unsigned long long') to 'size_t' (aka 'unsigned int') in initializer list
BROKEN=		does not build: strip: open /wrkdirs/usr/ports/databases/rocksdb-lite/work/stage/usr/local/lib/librocksdb-lite.so failed: No such file or directory

.include "${MASTERDIR}/Makefile"
