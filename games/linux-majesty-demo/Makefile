# New ports collection makefile for:	linux-majesty-demo
# Date created:		2009-01-30
# Whom:			Marcus von Appen <mva@sysfault.org>
#
# $FreeBSD$
#

PORTNAME=	majesty-demo
PORTVERSION=	1.0.0
CATEGORIES=	games linux
MASTER_SITES=	http://demofiles.linuxgamepublishing.com/majesty/
PKGNAMEPREFIX=	linux-
DISTNAME=	majesty_demo
EXTRACT_SUFX=	.run

MAINTAINER=	mva@sysfault.org
COMMENT=	Majesty Gold Demo

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12 \
		${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg \
		${LINUXBASE}/usr/lib/libSDL_mixer-1.2.so.0:${PORTSDIR}/audio/linux-sdl_mixer \
		${LINUXBASE}/usr/lib/libmikmod.so.2:${PORTSDIR}/audio/linux-mikmod \
		${LINUXBASE}/usr/lib/libogg.so.0:${PORTSDIR}/audio/linux-libogg \
		${LINUXBASE}/usr/lib/libvorbis.so.0:${PORTSDIR}/audio/linux-libvorbis

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_XLIB=	yes
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
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/bin/Linux/x86 && \
		${INSTALL_PROGRAM} maj_demo maj_demo.dynamic ${DATADIR}
	@${INSTALL_PROGRAM} ${WRKDIR}/majesty ${PREFIX}/bin/${PKGNAMEPREFIX}majesty
	@${CP} -R ${WRKSRC}/quests ${DATADIR}
	@${CP} -R ${WRKSRC}/data ${DATADIR}
.if !defined (NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
