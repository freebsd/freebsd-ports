# Created by: Mikhail Teterin
# $FreeBSD$

PORTREVISION=	2

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Gnu debugger with the Insight GUI front-end

BROKEN_powerpc64=	Does not build

MASTERDIR=	${.CURDIR:H}/gdb66
OPTIONS_SLAVE=	INSIGHT
CONFLICTS=	gdb-[6-9]*

MAKE_JOBS_UNSAFE=	yes

.include "${MASTERDIR}/Makefile"
