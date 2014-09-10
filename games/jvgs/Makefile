# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jvgs
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:C/\.[0-9]+$//}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Minimalistic platform game

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

USES=		cmake lua:51
USE_SDL=	sdl mixer
USE_GL=		gl glu

SUB_FILES=	${PORTNAME}

NO_CDROM=	contains data under CC-by-NC-SA

PLIST_FILES=	bin/${PORTNAME} libexec/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|main.lua|${DATADIR}/&|' ${WRKSRC}/src/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/jvgs ${STAGEDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKDIR}/jvgs ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "resources main.lua" ${STAGEDIR}${DATADIR}/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
