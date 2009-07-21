# New ports collection makefile for:    MySQL-scripts
# Date created:         28 Jan 2006
# Whom:                 Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mysql
PKGNAMESUFFIX=	-scripts

COMMENT=	Multithreaded SQL database (scripts)

MASTERDIR=	${.CURDIR}/../mysql54-server

PKGINSTALL=	mustnotexist
PKGMESSAGE=	mustnotexist
PLIST=		${PKGDIR}/pkg-plist.scripts

SCRIPTS_ONLY=	yes
USE_PERL5=	yes

.include "${MASTERDIR}/Makefile"
