PORTNAME=	libdatovka
DISTVERSION=	0.7.2
CATEGORIES=	devel
MASTER_SITES=	https://secure.nic.cz/files/datove_schranky/libdatovka/

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	ISDS client library
WWW=		https://gitlab.nic.cz/datovka/libdatovka

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
		gpgme>=0:security/gpgme \
		libgcrypt>=0:security/libgcrypt \
		libgpg-error>=0:security/libgpg-error \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2
RUN_DEPENDS=	gpgme>=0:security/gpgme \
		libgcrypt>=0:security/libgcrypt \
		libgpg-error>=0:security/libgpg-error

USES=		autoreconf gettext gmake gnome iconv libtool localbase \
		pkgconfig ssl tar:xz
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-fatalwarnings \
			--enable-openssl-backend \
			--with-docbook-xsl-stylesheets=${LOCALBASE}/share/xsl/docbook

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
