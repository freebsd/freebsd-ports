# New ports collection makefile for:	qrfcview
# Date created:		9 February 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qrfcview
PORTVERSION=	0.62
CATEGORIES=	deskutils
MASTER_SITES=	BERLIOS
EXTRACT_SUFX=	.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Graphical RFC viewer

USE_QT_VER=	4
QT_COMPONENTS=	gui network corelib designer
PLIST_FILES=	bin/qRFCView

pre-build:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE} -unix rfcview.pro

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/qRFCView ${PREFIX}/bin/

.include <bsd.port.mk>
