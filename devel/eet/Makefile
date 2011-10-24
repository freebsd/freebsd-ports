# New ports collection makefile for:	eet
# Date created:				08/08/2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	eet
DISTVERSION=	1.4.1
PORTEPOCH=	2
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2011-05-25/base/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enlightenment Data Handling Library

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg

LICENSE=	BSD
DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	eina librt_hack libtool_hack
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC} -L${OPENSSLLIB}" OPENSSL_LIBS="-lssl"
CONFIGURE_ARGS=	--disable-gnutls --enable-amalgamation

post-install:
	${REINPLACE_CMD} 's/ openssl//' ${PREFIX}/libdata/pkgconfig/eet.pc

.include <bsd.port.mk>
