# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	gspiceui
PORTVERSION=	1.1.00
PORTREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/gSpiceUI/${PORTNAME}-v${PORTVERSION}
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	GUI for ngspice and gnucap circuit simulators

LICENSE=	GPLv3

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_WX=		3.0
USES=		compiler:c++11-lib gmake pkgconfig

CXXFLAGS+=	-std=c++11

DESKTOP_ENTRIES=	"GSpiceUI" "Circuit Simulator GUI" \
			"${PREFIX}/share/pixmaps/gspiceui-48x48.xpm" \
			"gspiceui" "Science;Electronics;" false

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/gspiceui share/pixmaps/gspiceui-48x48.xpm \
		man/man1/gspiceui.1.gz

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CFLAGS:=	${CFLAGS:C/-O[2-9]/-O1/g}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share/gspiceui|${DOCSDIR}|g' \
	    ${WRKSRC}/src/main/HelpTasks.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gspiceui ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/icons/gspiceui-48x48.xpm \
	    ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_MAN} ${WRKSRC}/gspiceui.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR} \
		"! -name Makefile")
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for dir in lib sch
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${EXAMPLESDIR} \
		"! -name Makefile")
.endfor

.include <bsd.port.post.mk>
