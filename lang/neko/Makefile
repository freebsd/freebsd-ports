# $FreeBSD$

PORTNAME=	neko
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	lang

MAINTAINER=	penzin.dev@gmail.com
COMMENT=	Neko programming languages and virtual machine

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/bin/git:devel/git ${LOCALBASE}/include/apache22/httpd.h:www/apache22
LIB_DEPENDS=	libgc-threaded.so:devel/boehm-gc-threaded \
		libapr-1.so:devel/apr1 libaprutil-1.so:devel/apr1 \
		libpcre.so:devel/pcre libpcreposix.so:devel/pcre \
		libmbedtls.so:security/mbedtls libmbedcrypto.so:security/mbedtls libmbedx509.so:security/mbedtls \
		libfontconfig.so:x11-fonts/fontconfig libfreetype.so:print/freetype2 \
		libmysqlclient.so:databases/mysql56-client

USES=		cmake pkgconfig sqlite:3

USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 pango
USE_GITHUB=	yes
GH_ACCOUNT=	HaxeFoundation
# GH_PROJECT is the same as port name
GH_TAGNAME=	f8d55f1

USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/neko

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
