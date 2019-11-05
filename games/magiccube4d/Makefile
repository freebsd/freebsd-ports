# Created by: Jeremy <karlj000@unbc.ca>
# $FreeBSD$

PORTNAME=	magiccube4d
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.superliminal.com/cube/
DISTNAME=	mc4d-src-${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MagicCube4D is a four-dimensional analog of Rubik's cube

USES=		xorg
USE_XORG=	x11 xext xt sm ice xaw
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION:S/./_/}

PLIST_FILES=	bin/magiccube4d
PORTDOCS=	ChangeLog Intro.txt MagicCube4D-unix.txt \
		ideas.txt readme-unix.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|@DFLAGS@|${CXXFLAGS}|' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/magiccube4d ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
