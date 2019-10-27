# Created by: David Thiel <lx@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Persistent key-value store for fast storage environments (lite version)

LITE=		yes
MASTERDIR=	${.CURDIR}/../rocksdb

BROKEN=		tools/db_bench_tool.cc:3049:12: error: private field 'secondary_db_updates_' is not used [-Werror,-Wunused-private-field]
BROKEN_armv6=		does not build: db/compaction_job.cc:714:52: error: implicit conversion loses integer precision: 'uint64_t' (aka 'unsigned long long') to 'const size_t' (aka 'const unsigned int')
BROKEN_armv7=		does not build: db/compaction_job.cc:714:52: error: implicit conversion loses integer precision: 'uint64_t' (aka 'unsigned long long') to 'const size_t' (aka 'const unsigned int')

.include "${MASTERDIR}/Makefile"
