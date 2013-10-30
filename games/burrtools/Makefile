# Created by: ijliao
# $FreeBSD$

PORTNAME=	burrtools
PORTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF \
		http://www.c-s.li/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Puzzle solver

LICENSE=	GPLv3

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libxmlwrapp.so:${PORTSDIR}/textproc/xmlwrapp \
		libfltk.so:${PORTSDIR}/x11-toolkits/fltk \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_XORG=	x11 xt xext xmu xi
USE_GL=		glu
USES=		gmake
USE_GCC=	4.2+
GNU_CONFIGURE=	yes
CPPFLAGS+=	`fltk-config --cxxflags`
LDFLAGS+=	`fltk-config --ldflags`

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/burrTxt bin/burrTxt2 bin/burrGui

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/burrTxt ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/burrTxt2 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/gui/burrGui ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in burricons.ico AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples; ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
