# New ports collection makefile for:	knight
# Date created:		24 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	knights
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	games kde
MASTER_SITES=	http://dl.dropbox.com/u/2888238/Knights/

MAINTAINER=	syncer@gmail.com
COMMENT=	A KDE4 chess interface

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	kdegames.5:${PORTSDIR}/games/kdegames4
RUN_DEPENDS=	${LOCALBASE}/bin/gnuchess:${PORTSDIR}/games/gnuchess

LATEST_LINK=	${PORTNAME}-kde4
USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4 workspace
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
