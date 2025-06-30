PORTNAME=	libassetml
PORTVERSION=	1.2.1
PORTREVISION=	17
CATEGORIES=	devel gnome
MASTER_SITES=	SF/ofset/${PORTNAME}/${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to share image and audio files between projects
WWW=		http://www.ofset.org/assetml/

BUILD_DEPENDS=	texi2html:textproc/texi2html
LIB_DEPENDS=	libpopt.so:devel/popt

USES=		gettext gmake gnome libtool:keepla makeinfo pathfix pkgconfig
USE_GNOME=	gnomeprefix glib20 libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip

INFO=	libassetml

post-patch:
	@${REINPLACE_CMD} -e 's,libdir)/locale,datadir)/locale,g' ${WRKSRC}/po/Makefile.in.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/assetml

.include <bsd.port.mk>
