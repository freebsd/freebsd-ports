# New ports collection makefile for:	eet
# Date created:				08/08/2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	eet
DISTVERSION=	1.4.0.beta
PORTEPOCH=	2
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2010-10-03/base/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Enlightenment Data Handling Library

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg

LICENSE=	BSD
DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	eina librt_hack libtool_hack
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

CONFIGURE_ARGS=	--disable-gnutls

.include <bsd.port.mk>
