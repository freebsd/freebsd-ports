# New ports collection makefile for:	qsvn
# Date created:		2007-11-17
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	qsvn
DISTVERSION=	0.6.1
DISTVERSIONSUFFIX=	-src
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.anrichter.net/projects/qsvn/chrome/site/

MAINTAINER=	makc@issp.ac.ru
COMMENT=	Qt based GUI frontend for Subversion

LIB_DEPENDS+=	svn_client-1:${PORTSDIR}/devel/subversion

USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build uic_build rcc_build qmake_build qt3support_build
USE_LDCONFIG=	yes
USE_CMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

DESKTOP_ENTRIES="QSvn" "SVN client" "" "qsvn" "" false

.include <bsd.port.mk>
