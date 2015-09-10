# $FreeBSD$

PKGNAMESUFFIX=	-subversion

COMMENT=	Distributed source code management tool with FreeBSD subversion bindings

MASTERDIR=	${.CURDIR}/../git

DESCR=		${.CURDIR}/pkg-descr

OPTIONS_SLAVE=	SVN

CONFLICTS_INSTALL=	git-[0-9]* git-lite-[0-9]*

DISTINFO_FILE=	${MASTERDIR}/distinfo

.include "${MASTERDIR}/Makefile"
