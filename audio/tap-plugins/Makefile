PORTNAME=	tap-plugins
PORTVERSION=	0.7.2
CATEGORIES=	audio
MASTER_SITES=	SF/tap-plugins/tap-plugins/${PORTVERSION}

MAINTAINER=	taku@tackymt.homeip.net
COMMENT=	LADSPA Plugins by Tom Szilagy

LICENSE=	GPLv2

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I. -c -fPIC -DPIC" \
		LDFLAGS="-nostartfiles -shared -Wl,-Bsymbolic -lm"

post-patch:
	@${GREP} -lR "<stdint\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<stdint\.h>|<inttypes.h>|g'

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/ladspa
	${INSTALL_DATA} ${WRKSRC}/*.so ${STAGEDIR}${PREFIX}/lib/ladspa/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ladspa/*.so
	${MKDIR} ${STAGEDIR}${PREFIX}/share/ladspa/rdf/
	${INSTALL_DATA} ${WRKSRC}/tap-plugins.rdf \
		${STAGEDIR}${PREFIX}/share/ladspa/rdf/

.include <bsd.port.mk>
