# New ports collection Makefile for:   alienwah
# Date created:                        13 May 2002
# Whom:                                Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	alienwah
PORTVERSION=	1.13
CATEGORIES=	audio
MASTER_SITES=	http://plugin.org.uk/releases/alienwah/

MAINTAINER=	arved@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

do-install:
	@${INSTALL_DATA} ${WRKSRC}/aw.so ${LOCALBASE}/lib/ladspa

.include <bsd.port.mk>
