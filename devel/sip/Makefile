# New ports collection makefile for:	sip
# Version required:	0.9
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@home.com
#
# $FreeBSD$
#

PORTNAME=	sip
PORTVERSION=	0.11.1
CATEGORIES=	devel python
MASTER_SITES=	http://www.river-bank.demon.co.uk/software/

MAINTAINER=	adsharma@home.com

BUILD_DEPENDS=	${LOCALBASE}/include/python1.5/Python.h:${PORTSDIR}/lang/python

USE_LIBTOOL=	yes
INSTALL_SHLIBS=	yes
USE_QT=		yes
CONFIGURE_ARGS=	--enable-qt --with-qt-includes=${X11BASE}/include/X11/qt
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	LDFLAGS=-lgcc

.include <bsd.port.mk>
