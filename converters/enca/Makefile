# Ports collection makefile for:  enca
# Date created:			  Fri Sep 20, 2002
# Whom:				  Alexandr Kovalenko <never@nevermind.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	enca
PORTVERSION=	0.10.3
CATEGORIES=	converters textproc
MASTER_SITES=	http://trific.ath.cx/Ftp/enca/

MAINTAINER=	never@nevermind.kiev.ua

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc/enca \
		--without-librecode \
		--with-libiconv=${LOCALBASE}
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"

MAN1=	enca.1
MLINKS=	enca.1 enconv.1

.include <bsd.port.mk>
