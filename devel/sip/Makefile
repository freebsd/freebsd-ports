# New ports collection makefile for:	sip
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@home.com
#
# $FreeBSD$
#

PORTNAME=	sip
PORTVERSION=	2.2
CATEGORIES=	devel python
MASTER_SITES=	http://www.river-bank.demon.co.uk/software/

MAINTAINER=	adsharma@sharmas.dhs.org

USE_PYTHON=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_QT2=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-qt --with-qt-includes=${X11BASE}/include/qt2
CONFIGURE_ENV=	LDFLAGS=-lgcc

.include <bsd.port.mk>
