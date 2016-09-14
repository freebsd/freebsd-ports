# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qiviewer
PORTVERSION=	0.5.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Fast and lightweight image viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${PORTNAME}/COPYING

BROKEN=		Unfetchable (google code has gone away)

USES=		desktop-file-utils qmake tar:bzip2
USE_QT4=	corelib gui imageformats_run linguisttools_build \
		moc_build rcc_build uic_build

PLIST_FILES=	bin/qiviewer \
		share/applications/qiviewer.desktop \
		share/qiviewer/locale/el.qm \
		share/qiviewer/locale/es_AR.qm \
		share/qiviewer/locale/es_ES.qm

WRKSRC=		${WRKDIR}/${PORTNAME}/src

OPTIONS_DEFINE=	WEBP
WEBP_DESC=	Support for WebP image format (experimental)
WEBP_QMAKE_ON=	CONFIG+=enable-webp

post-configure:
	@${REINPLACE_CMD} -e 's|lrelease|lrelease-qt4|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
