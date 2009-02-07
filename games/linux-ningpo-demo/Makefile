# New ports collection makefile for:	linux-ningpo-demo
# Date created:		2009-01-31
# Whom:			Marcus von Appen <mva@sysfault.org>
#
# $FreeBSD$
#

PORTNAME=	ningpo-demo
PORTVERSION=	1.05.04
CATEGORIES=	games linux
MASTER_SITES=	http://demofiles.linuxgamepublishing.com/ningpo/
PKGNAMEPREFIX=	linux-
DISTNAME=	ningpo_demo
EXTRACT_SUFX=	.run

MAINTAINER=	mva@sysfault.org
COMMENT=	NingPo Mahjong Demo - a feature rich Mahjong game

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12 \
		${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg \
		${LINUXBASE}/usr/lib/libSDL_mixer-1.2.so.0:${PORTSDIR}/audio/linux-sdl_mixer \
		${LINUXBASE}/usr/lib/libmikmod.so.2:${PORTSDIR}/audio/linux-mikmod \
		${LINUXBASE}/usr/lib/libogg.so.0:${PORTSDIR}/audio/linux-libogg \
		${LINUXBASE}/usr/lib/libvorbis.so.0:${PORTSDIR}/audio/linux-libvorbis \
		${LINUXBASE}/lib/libasound.so.2:${PORTSDIR}/audio/linux-alsa-lib

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_XLIB=	yes
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	ningpo
PORTDOCS=	README README.licenses license.txt

.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${TAIL} +377 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} jxf -

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/bin/Linux/x86/Bin/ningpo_demo
	${BRANDELF} -t Linux ${WRKSRC}/bin/Linux/x86/Bin/ningpo_demo.dynamic

do-install:
	@${MKDIR} ${DATADIR}/Bin
	@cd ${WRKSRC}/bin/Linux/x86/Bin && \
		${INSTALL_PROGRAM} ningpo_demo ningpo_demo.dynamic ${DATADIR}/Bin
	@${INSTALL_PROGRAM} ${WRKDIR}/ningpo ${PREFIX}/bin/${PKGNAMEPREFIX}ningpo
	@${CP} -R ${WRKSRC}/Resources ${DATADIR}
.if !defined (NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
