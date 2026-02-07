PORTNAME=	libglademm
PORTVERSION=	2.6.7
PORTREVISION=	16
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for libglade2 library
WWW=		http://gtkmm.sourceforge.net/

OPTIONS_DEFINE=	DOCS

LIB_DEPENDS=	libgtkmm-2.4.so:x11-toolkits/gtkmm24

USES=		compiler:c++11-lang gmake gnome libtool:keepla pathfix \
		pkgconfig tar:bzip2 xorg
USE_CXXSTD=	c++11
USE_XORG=	x11 ice
USE_GNOME=	libglade2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static
INSTALL_TARGET=	install-strip
BINARY_WRAPPERS=	gm4

PLIST_SUB=	VERSION="2.4" API_VERSION="2.4"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples//' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|\(-lglibmm\)|-L\$$(GMM_PROCDIR)/../.. \1|" \
		${WRKSRC}/tools/extra_defs_gen/Makefile.in

.include <bsd.port.mk>
