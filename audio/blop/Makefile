# New ports collection Makefile for:	blop
# Date created:			15 May 2002
# Whom:				Tilman Linneweh <freebsdports@arved.de>
#
# $FreeBSD$
#

PORTNAME=	blop
PORTVERSION=	0.1.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	freebsdports@arved.de

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

PLUGINS=	sawtooth.so \
		square.so \
		pulse.so \
		triangle.so
PLUGIN_DIR=	${LOCALBASE}/lib/ladspa

do-install:
.for file in ${PLUGINS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PLUGIN_DIR}
.endfor

.include <bsd.port.mk>
