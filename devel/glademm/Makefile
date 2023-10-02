PORTNAME=	glademm
PORTVERSION=	2.6.0
PORTREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	http://home.wtal.de/petig/Gtk/
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ code generator backend for glade and glade2
WWW=		http://home.wtal.de/petig/Gtk/

USES=		gmake gnome pathfix pkgconfig
USE_CXXSTD=	c++14
USE_GNOME=	gnomeprefix

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/glade-- bin/glademm-embed

post-patch:
	@${RM} ${WRKSRC}/src/getopt.*
	@${REINPLACE_CMD} \
		-Ee '/^@AMDEP/!s|getopt([^[:space:]])+||g' \
		-Ee '/^@AMDEP(.)+getopt/d' \
			${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
