# New ports collection makefile for:	klatexformula
# Date created:		2009-11-18
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	klatexformula
PORTVERSION=	3.1.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Convert LaTeX formula to image

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_QT4=	gui xml dbus designer_build \
		qmake_build moc_build rcc_build uic_build
USE_TEX=	latex dvipsk
HAS_CONFIGURE=	yes
USE_GHOSTSCRIPT=	yes
QMAKE_ARGS=	QMAKE=${QMAKE} INSTALLPREFIX=${PREFIX} \
		BACKEND_LIBDIR=lib

STRIP_FILES=	bin/klatexformula

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKE_ARGS}

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}

.include <bsd.port.mk>
