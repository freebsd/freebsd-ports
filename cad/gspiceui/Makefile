# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	gspiceui
PORTVERSION=	1.0.00
PORTREVISION=	6
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/gSpiceUI/${PORTNAME}-v${PORTVERSION}
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	GUI frontend to gnucap and ngspice circuit simulators

LICENSE=	GPLv2

RUN_DEPENDS=	# none if no options are set

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_GROUP=	BACKEND

OPTIONS_GROUP_BACKEND=	GNUCAP NGSPICE

GNUCAP_DESC=	Depend on gnucap as a simulation backend
NGSPICE_DESC=	Depend on ngspice as a simulation backend

OPTIONS_DEFAULT=	NGSPICE

USE_WX=		2.8+
WX_UNICODE=	yes
USES=		gmake compiler:c++11-lib

DESKTOP_ENTRIES=	"GSpiceUI" "Circuit Simulator GUI" \
			"${PREFIX}/share/pixmaps/gspiceui-48x48.xpm" \
			"gspiceui" "Science;Electronics;" false

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/gspiceui share/pixmaps/gspiceui-48x48.xpm \
		man/man1/gspiceui.1.gz

GNUCAP_RUN_DEPENDS=	gnucap:${PORTSDIR}/cad/gnucap
NGSPICE_RUN_DEPENDS=	ngspice:${PORTSDIR}/cad/ngspice_rework

post-patch:
	@${REINPLACE_CMD} -e \
		's|:= -Ofast -pipe|+= -I.|g ; \
		 s|^INCLUDES |#INCLUDES |g ; \
		 s|$$(WXCFG)|$$(WX_CONFIG)|g ; \
		 s|$$(CC)|$$(CXX)|g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e \
		's|share/gspiceui|${DOCSDIR}|g' \
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

.include <bsd.port.mk>
