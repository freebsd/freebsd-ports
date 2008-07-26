# New ports collection makefile for:    MySQL-scripts
# Date created:         Mon Feb 23 15:01:35 CET 2004
# Whom:                 Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mysql
PORTREVISION=	0
PKGNAMESUFFIX=	-scripts

COMMENT=	Multithreaded SQL database (scripts)

MASTERDIR=	${.CURDIR}/../mysql40-server

PKGINSTALL=	mustnotexist
PLIST=		${PKGDIR}/pkg-plist.scripts

SCRIPTS_ONLY=	yes

.include "${MASTERDIR}/Makefile"
