# New ports collection Makefile for:   alienwah
# Date created:                        13 May 2002
# Whom:                                Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	alienwah
PORTVERSION=	1.13
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://plugin.org.uk/releases/alienwah/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"Paul Nasca's AlienWah LADSPA Plugin"

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
PLIST_FILES=	lib/ladspa/aw.so

do-install:
	@${INSTALL_DATA} ${WRKSRC}/aw.so ${LOCALBASE}/lib/ladspa

.include <bsd.port.mk>
