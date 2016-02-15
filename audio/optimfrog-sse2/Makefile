# $FreeBSD$

PKGNAMESUFFIX=	-sse2

MASTERDIR=	${.CURDIR}/../optimfrog
COMMENT=	Best-ratio lossless audio codec (SSE2 required)

CONFLICTS_INSTALL=	optimfrog-[0-9]*

ONLY_FOR_ARCHS=	i386
OPTIONS_DEFAULT=	SSE2

.include "${MASTERDIR}/Makefile"
