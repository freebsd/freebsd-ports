# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	nonpareil
PORTVERSION=	0.79
PORTREVISION=	7
CATEGORIES=	emulators
MASTER_SITES=	http://nonpareil.brouhaha.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simulator for many HP calculators

LICENSE=	GPLv2 # only
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		bison gnome pkgconfig scons sdl
USE_GNOME=	gtk20 libxml2
USE_SDL=	sdl

PORTDOCS=	CREDITS DEBUGGING README TODO

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%CFLAGS%%|${CFLAGS}| ; \
		 s|%%CC%%|${CC}|' ${WRKSRC}/src/SConscript
	@${REINPLACE_CMD} -E \
		"s|('/usr/local')|\1,PathVariable.PathAccept|" ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e \
		's|<stdint.h>|<inttypes.h>|g' ${WRKSRC}/src/*.[cly]

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
