# New ports collection Makefile for:	tap-plugins
# Date created:				2004-05-19
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	tap-plugins
PORTVERSION=	0.5.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tap-plugins

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LADSPA Plugins by Tom Szilagy

USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	${REINPLACE_CMD} -e "s,-lrt,,; \
	s,-O3 -Wall -fomit-frame-pointer -fstrength-reduce -funroll-loops -ffast-math,${CFLAGS}," \
		${WRKSRC}/Makefile

do-install:
	${MKDIR} ${PREFIX}/lib/ladspa
	${INSTALL_DATA} ${WRKSRC}/*.so ${PREFIX}/lib/ladspa/
	${MKDIR} ${PREFIX}/share/ladspa/rdf/
	${INSTALL_DATA} ${WRKSRC}/tap-plugins.rdf ${PREFIX}/share/ladspa/rdf/

.include <bsd.port.mk>
