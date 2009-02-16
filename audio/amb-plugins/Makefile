# New ports collection makefile for:	amb-plugins
# Date created:		2007-08-28
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	amb-plugins
PORTVERSION=	0.4.0
CATEGORIES=	audio
MASTER_SITES=	http://www.kokkinizita.net/linuxaudio/downloads/
DISTNAME=	AMB-plugins-${PORTVERSION}

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	A set of ambisonics plugins, mainly to be used within Ardour

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_GMAKE=	yes

PLIST_FILES=	lib/ladspa/ambisonic1.so lib/ladspa/ambisonic2.so

do-install:
		${INSTALL_DATA} ${WRKSRC}/ambisonic1.so ${PREFIX}/lib/ladspa
		${INSTALL_DATA} ${WRKSRC}/ambisonic2.so ${PREFIX}/lib/ladspa

.include <bsd.port.mk>
