# New ports collection Makefile for:   alienwah
# Date created:                        13 May 2002
# Whom:                                Tilman Linneweh <freebsdports@arved.de
#
# $FreeBSD$
#

PORTNAME=	alienwah
PORTVERSION=	1.13
CATEGORIES=	audio
MASTER_SITES=	http://plugin.org.uk/releases/alienwah/

MAINTAINER=	freebsdports@arved.de

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

do-install:
	@${INSTALL_DATA} ${WRKSRC}/aw.so ${LOCALBASE}/lib/ladspa

.include <bsd.port.mk>
