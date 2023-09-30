PORTNAME=	xcoral
PORTVERSION=	3.47
PORTREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	http://xcoral.free.fr/

PATCH_SITES=	http://aldan.algebra.com/~mi/port-stuff/
PATCHFILES=	xcoral-alpheus-and-peneus-2020.patch.bz2

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Multiwindow mouse-based text editor for X
WWW=		http://xcoral.free.fr/

LICENSE=	GPLv2

LIB_DEPENDS=	libgnuregex.so.[6-9]:devel/libgnuregex

USES=		bison compiler:c11 localbase:ldflags xorg
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
LIBS+=		-lgnuregex
EXTRACT_AFTER_ARGS=	--exclude BR_Parser.[ch]

PLIST_SUB=	VERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's| regex\.[co] | |g ; \
		 s| -g | |g' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xcoral ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/SmacLib/* ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
