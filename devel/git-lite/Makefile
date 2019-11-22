# $FreeBSD$

PKGNAMESUFFIX=	-lite

COMMENT=	Distributed source code management tool (lite package)

MASTERDIR=	${.CURDIR}/../git

DESCR=		${.CURDIR}/pkg-descr

OPTIONS_EXCLUDE=GUI SVN GITWEB CONTRIB P4 CVS PERL

CONFLICTS_INSTALL=	git-[0-9]* git-gui-[0-9]*

DISTINFO_FILE=	${MASTERDIR}/distinfo

.include "${MASTERDIR}/Makefile"
