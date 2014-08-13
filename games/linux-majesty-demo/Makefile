# Created by: Marcus von Appen <mva@sysfault.org>
# $FreeBSD: head/games/linux-majesty-demo/Makefile 340092 2014-01-17 18:09:49Z mva $

PORTNAME=	majesty-demo
PORTVERSION=	1.0.0
CATEGORIES=	games linux
MASTER_SITES=	http://demofiles.linuxgamepublishing.com/majesty/
PKGNAMEPREFIX=	linux-
DISTNAME=	majesty_demo
EXTRACT_SUFX=	.run

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Majesty Gold Demo

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	sdl12 jpeg sdlmixer mikmod libogg libvorbis xorglibs
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	majesty
PORTDOCS=	README README.licenses EULA

.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${TAIL} +377 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} jxf -

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/bin/Linux/x86/maj_demo
	${BRANDELF} -t Linux ${WRKSRC}/bin/Linux/x86/maj_demo.dynamic

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/bin/Linux/x86 && \
		${INSTALL_PROGRAM} maj_demo maj_demo.dynamic ${STAGEDIR}${DATADIR}
	@${INSTALL_PROGRAM} ${WRKDIR}/majesty \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}majesty
	@${CP} -R ${WRKSRC}/quests ${STAGEDIR}${DATADIR}
	@${CP} -R ${WRKSRC}/data ${STAGEDIR}${DATADIR}
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
