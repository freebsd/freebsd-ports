# New ports collection makefile for:	qrfcview
# Date created:		9 February 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qrfcview
PORTVERSION=	0.62
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	CENKES BERLIOS
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Graphical RFC viewer

USE_QT_VER=	4
QT_COMPONENTS=	gui network corelib qmake_build uic_build moc_build rcc_build
PLIST_FILES=	bin/qRFCView

do-configure:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE} -unix rfcview.pro

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/qRFCView ${PREFIX}/bin/

.include <bsd.port.mk>
