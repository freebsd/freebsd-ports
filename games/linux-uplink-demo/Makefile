# Created by: Marcus von Appen <mva@sysfault.org>
# $FreeBSD$

PORTNAME=	uplink-demo
PORTVERSION=	1.55
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	http://www.introversion.co.uk/uplink/downloads/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION}DEMO
EXTRACT_SUFX=	.sh

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High tech computer crime and industrial espionage on the Internet

ONLY_FOR_ARCHS=	i386 amd64
USES=		linux
USE_LINUX=	dri jpeg libvorbis mikmod sdl12 sdlmixer xorglibs
USE_LDCONFIG=	yes
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	uplink
SUB_LIST=	LINUXBASE=${LINUXBASE}
DOCFILES=	license.txt mods.txt Readme-UplinkSupport.txt readme.txt

OPTIONS_DEFINE=	DOCS

do-extract:
	@cd ${WRKSRC} && ${TAIL} +376 ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxf -

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/lib && \
		${INSTALL_PROGRAM} uplink.bin.x86 libftgl.so.0 ${STAGEDIR}${DATADIR} && \
		${INSTALL_DATA} *.dat ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/uplink \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}uplink
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}/${file}
.endfor

.include <bsd.port.mk>
