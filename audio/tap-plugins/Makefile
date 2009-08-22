# New ports collection Makefile for:	tap-plugins
# Date created:				2004-05-19
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	tap-plugins
PORTVERSION=	0.7.1
CATEGORIES=	audio
MASTER_SITES=	SF/tap-plugins/tap-plugins/${PORTVERSION}

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	LADSPA Plugins by Tom Szilagy

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I. -c -fPIC -DPIC" \
		LDFLAGS="-nostartfiles -shared -Wl,-Bsymbolic -lm"

post-patch:
	@${GREP} -lR "<stdint\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<stdint\.h>|<inttypes.h>|g'

do-install:
	${MKDIR} ${PREFIX}/lib/ladspa
	${INSTALL_DATA} ${WRKSRC}/*.so ${PREFIX}/lib/ladspa/
	${MKDIR} ${PREFIX}/share/ladspa/rdf/
	${INSTALL_DATA} ${WRKSRC}/tap-plugins.rdf ${PREFIX}/share/ladspa/rdf/

.include <bsd.port.mk>
