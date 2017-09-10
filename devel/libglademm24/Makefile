# Created by: Alexander Nedotsukov <bland@mail.ru>
# $FreeBSD$
#   $MCom: ports/devel/libglademm24/Makefile,v 1.10 2008/09/22 11:42:53 kwm Exp $

PORTNAME=	libglademm
PORTVERSION=	2.6.7
PORTREVISION=	9
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libglade2 library

OPTIONS_DEFINE=	DOCS

LIB_DEPENDS=	libgtkmm-2.4.so:x11-toolkits/gtkmm24
BUILD_DEPENDS=	gm4:devel/m4

USE_XORG=	x11 ice
USES=		compiler:c++11-lang gmake libtool:keepla pathfix pkgconfig \
		tar:bzip2
USE_CXXSTD=	c++11
USE_GNOME=	libglade2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION="2.4" API_VERSION="2.4"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples//' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|\(-lglibmm\)|-L\$$(GMM_PROCDIR)/../.. \1|" \
		${WRKSRC}/tools/extra_defs_gen/Makefile.in

.include <bsd.port.mk>
