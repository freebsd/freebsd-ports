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
USE_QT_VER=	2
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-qt
CONFIGURE_ENV=	LDFLAGS=-lgcc

.include <bsd.port.mk>
