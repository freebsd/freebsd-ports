# Created by: Mikhail Teterin
# $FreeBSD$

PORTREVISION=	2

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Gnu debugger with the Insight GUI front-end

LATEST_LINK=	insight

MASTERDIR=	${.CURDIR:H}/gdb66
OPTIONS_SLAVE=	INSIGHT
CONFLICTS=	gdb-[6-9]*

MAKE_JOBS_UNSAFE=	yes

.include "${MASTERDIR}/Makefile"
