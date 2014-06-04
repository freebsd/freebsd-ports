# $FreeBSD$

PKGNAMESUFFIX=	-subversion

COMMENT=	Distributed source code management tool with FreeBSD subversion bindings

MASTERDIR=	${.CURDIR}/../git

DESCR=		${.CURDIR}/pkg-descr

OPTIONS_SLAVE=	SVN

CONFLICTS?=	git-[0-9]*

DISTINFO_FILE=	${MASTERDIR}/distinfo

.include "${MASTERDIR}/Makefile"
