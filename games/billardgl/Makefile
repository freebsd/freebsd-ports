# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	billardgl
PORTVERSION=	1.75
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/BillardGL%20${PORTVERSION}
DISTNAME=	BillardGL-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	OpenGL pool billiard simulation

LICENSE=	GPLv2 # from website

WRKSRC_SUBDIR=	src

USES=		dos2unix gl xorg
DOS2UNIX_FILES=	Makefile bmp.cpp
USE_GL=		gl glu glut
USE_XORG=	x11 xext xmu xi
USE_CXXSTD=	c++98

PORTDOCS=	README
PORTDATA=	*
PLIST_FILES=	bin/billardgl \
		share/pixmaps/billardgl.bmp

DESKTOP_ENTRIES="${PORTNAME}" \
		"" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.bmp" \
		"${PORTNAME}" \
		"Game;Simulation;" \
		""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/BillardGL/|${DATADIR}/|' ${WRKSRC}/Namen.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/BillardGL ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "Texturen lang" ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Texturen/1/dreizehn.bmp ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.bmp

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
