# Ports collection makefile for:  pear-DB_Sqlite_Tools
# Date created:			  29 April 2007
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DB_Sqlite_Tools
PORTVERSION=	0.1.7
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	an object oriented interface to backup Sqlite databases

BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB \
		${PEARDIR}/Log/null.php:${PORTSDIR}/sysutils/pear-Log
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	DB
FILES=		DB/Sqlite/Tools.php DB/Sqlite/Tools/ArcFour.php DB/Sqlite/Tools/DBC.php \
		DB/Sqlite/Tools/XMLParser.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
