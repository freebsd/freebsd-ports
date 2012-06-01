# New ports collection makefile for:	qiviewer
# Date created:		2011-04-02
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	qiviewer
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Fast and lightweight image viewer

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui xml dbus linguist_build qmake_build moc_build \
		rcc_build uic_build
QMAKEFLAGS+=	PREFIX="${PREFIX}"

PLIST_FILES=	bin/qiviewer \
		share/applications/qiviewer.desktop \
		share/qiviewer/locale/el.qm \
		share/qiviewer/locale/es_AR.qm \
		share/qiviewer/locale/es_ES.qm
PLIST_DIRS=	share/qiviewer/locale \
		share/qiviewer \
		share/applications

WRKSRC=		${WRKDIR}/${PORTNAME}/src

OPTIONS=	WEBP "Support for WebP image format (experimental)" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_WEBP)
QMAKEFLAGS+=	CONFIG+=enable-webp
.endif

do-configure:
	@cd ${WRKSRC} && ${QMAKE} ${QMAKEFLAGS}

post-configure:
	${REINPLACE_CMD} -e 's|lrelease|lrelease-qt4|g' \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>
