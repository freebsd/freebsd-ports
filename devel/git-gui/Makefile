# $FreeBSD$

PKGNAMESUFFIX=	-gui

COMMENT=	Distributed source code management tool (GUI enabled)

MASTERDIR=	${.CURDIR}/../git

DESCR=		${.CURDIR}/pkg-descr

OPTIONS_SLAVE=	GUI

CONFLICTS_INSTALL=	git-[0-9]* git-lite-[0-9]*

DISTINFO_FILE=	${MASTERDIR}/distinfo

.include "${MASTERDIR}/Makefile"
