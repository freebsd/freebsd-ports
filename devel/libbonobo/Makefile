# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libbonobo/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTNAME=	libbonobo
PORTVERSION=	2.32.1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Component and compound document system for GNOME2

USES=		tar:bzip2

.if !defined(REFERENCE_PORT)

LICENSE=	GPLv2 LGPL21  # former for tools, latter for library
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libpopt.so:devel/popt

USES+=		bison gettext gmake gnome libtool:keepla localbase:ldflags \
		pathfix perl5 pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	intlhack libxml2 orbit2 referencehack
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
LDFLAGS+=	-pthread
MAKE_ENV=	gnomelocaledir=${PREFIX}/share/locale

post-patch:
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure \
		${WRKSRC}/activation-server/Makefile.in

.include <bsd.port.mk>

.endif
