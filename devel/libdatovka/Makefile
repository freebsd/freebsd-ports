PORTNAME=	libdatovka
DISTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://secure.nic.cz/files/datove_schranky/libdatovka/

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	ISDS client library
WWW=		https://gitlab.nic.cz/datovka/libdatovka

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
		expat>0:textproc/expat2 \
		gpgme>0:security/gpgme \
		libgcrypt>0:security/libgcrypt \
		libiconv>0:converters/libiconv \
		pkgconf:devel/pkgconf \
		xsltproc:textproc/libxslt
LIB_DEPENDS+=	libassuan.so:security/libassuan \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libxml2.so:textproc/libxml2

USES=		autoreconf gettext gmake gnome libtool localbase ssl tar:xz
USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes

GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS+=	--disable-fatalwarnings \
			--enable-openssl-backend \
			--with-docbook-xsl-stylesheets=${LOCALBASE}/share/xsl/docbook

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
