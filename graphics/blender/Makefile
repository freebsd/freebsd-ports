# New ports collection makefile for:    blender
# Date created:         14 November 2000
# Whom:                 Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$
#

PORTNAME=	blender
PORTVERSION=	2.25
CATEGORIES=	graphics games
MASTER_SITES=	http://download.blender.org/release/Publisher${PORTVERSION}/
DISTNAME=	blender-publisher-${PORTVERSION}-freebsd-4.2-i386
DIST_SUBDIR=	blender

MAINTAINER=	freebsd-admin@blender.nl

USE_X_PREFIX=	YES
NO_BUILD=	YES
ONLY_FOR_ARCHS=	i386
USE_MESA=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/blenderplayer ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/blenderpublisher ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/blender
	${MKDIR} ${PREFIX}/lib/blender/plugins/texture \
		${PREFIX}/lib/blender/plugins/sequence
.for SEQ in blur.so scatter.so showzbuf.so
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/sequence/${SEQ} \
		${PREFIX}/lib/blender/plugins/sequence
.endfor
.for TEXT in clouds2.so tiles.so
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/texture/${TEXT} \
		${PREFIX}/lib/blender/plugins/texture
.endfor
	${MKDIR} ${PREFIX}/share/doc/blender
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/blender
	${INSTALL_DATA} ${WRKSRC}/copyright.txt ${PREFIX}/share/doc/blender
	${INSTALL_DATA} ${WRKSRC}/playerlicense.txt ${PREFIX}/share/doc/blender

.include <bsd.port.mk>
