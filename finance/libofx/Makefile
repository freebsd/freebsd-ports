PORTNAME=	libofx
PORTVERSION=	0.10.9
PORTREVISION=	2
CATEGORIES=	finance
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTVERSION}/ \
		SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	OpenSource implementation of the OFX (Open Financial eXchange)
WWW=		https://libofx.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libxml++-2.6.so:textproc/libxml++26 \
		libosp.so:textproc/opensp

USES=		cpe gettext-runtime gmake gnome iconv libtool localbase pathfix pkgconfig \
		compiler:c++11-lang
USE_CXXSTD=	c++11
USE_GNOME=	glib20 glibmm libsigc++20 libxml2
CONFIGURE_ARGS=	--disable-doxygen --disable-dot --disable-gengetopt \
		--with-opensp-includes=${LOCALBASE}/include/OpenSP \
		--with-opensp-libs=${LOCALBASE}/lib
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
PORTDOCS=	*
CPE_VENDOR=	libofx_project

OPTIONS_DEFINE=	DOCS

post-install:
	${RM} ${STAGEDIR}${DOCSDIR}/COPYING

.include <bsd.port.mk>
