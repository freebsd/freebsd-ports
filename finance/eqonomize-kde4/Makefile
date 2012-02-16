# New ports collection makefile for:	eqonomize
# Date created:				6 August 2007
# Whom:					Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	eqonomize
PORTVERSION=	0.6
PORTREVISION=	7
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}/Eqonomize%21/${PORTVERSION}
PKGNAMESUFFIX=	-kde4

MAINTAINER=	cm@therek.net
COMMENT=	A personal accounting software

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml

USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui network svg xml qmake_build moc_build uic_build rcc_build
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
INSTALLS_ICONS=	yes

DATADIR=	${PREFIX}/share/apps/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc

post-patch:
#Fix build with kdelibs>=4.5.0
	${REINPLACE_CMD} -e 's,V4.1.2-Based,V4.2-Based,g' \
		${WRKSRC}/doc/*/index.docbook

.include <bsd.port.mk>
