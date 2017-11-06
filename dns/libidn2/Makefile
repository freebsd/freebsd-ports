# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libidn2
PORTVERSION=	2.0.4
CATEGORIES=	dns
MASTER_SITES=	GNU/libidn

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of IDNA2008 internationalized domain names

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libunistring.so:devel/libunistring

CONFIGURE_ARGS=	--disable-nls \
		--with-libunistring-prefix=${LOCALBASE} \
		ac_cv_prog_RONN=${TRUE}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		charsetfix gmake iconv libtool localbase pathfix

INFO=		libidn2

post-patch:
	@${REINPLACE_CMD} -e '/^TMPDIR = /d' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
