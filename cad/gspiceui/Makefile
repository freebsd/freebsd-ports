PORTNAME=	gspiceui
DISTVERSION=	1.1.00
PORTREVISION=	8
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/gSpiceUI/${PORTNAME}-v${DISTVERSION}
DISTNAME=	${PORTNAME}-v${DISTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	GUI for ngspice and gnucap circuit simulators
WWW=		https://sourceforge.net/projects/gspiceui/

LICENSE=	GPLv3

USES=		compiler:c++11-lib gmake pkgconfig
USE_WX=		3.0

CXXFLAGS+=	-std=c++11

DESKTOP_ENTRIES=	"GSpiceUI" "Circuit Simulator GUI" \
			"${PREFIX}/share/pixmaps/gspiceui-48x48.xpm" \
			"gspiceui" "Science;Electronics;" false

PLIST_FILES=	bin/gspiceui share/pixmaps/gspiceui-48x48.xpm \
		share/man/man1/gspiceui.1.gz
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CFLAGS:=	${CFLAGS:C/-O[2-9]/-O1/g}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/share/gspiceui|${DOCSDIR:S|^${PREFIX}||}|g' \
	    ${WRKSRC}/src/main/HelpTasks.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gspiceui ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/icons/gspiceui-48x48.xpm \
	    ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_MAN} ${WRKSRC}/gspiceui.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR} \
		"! -name Makefile")
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "lib sch" ${STAGEDIR}${EXAMPLESDIR} \
		"! -name Makefile")

.include <bsd.port.post.mk>
