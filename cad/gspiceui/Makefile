# New ports collection makefile for:	gspiceui
# Date created:		30 April 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	gspiceui
PORTVERSION=	1.0.00
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/gSpiceUI/${PORTNAME}-v${PORTVERSION}
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI frontend for gnucap/ng-spice circuit simulators

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/License

RUN_DEPENDS=	gwave:${PORTSDIR}/cad/gwave

OPTIONS_DEFINE=	NGSPICE GNUCAP EXAMPLES DOCS
OPTIONS_DEFAULT=	NGSPICE
NGSPICE_DESC=	Use ng-spice as backend
GNUCAP_DESC=	Use gnucap as backend

USE_WX=		2.6+
WX_UNICODE=	yes
USE_GCC=	4.6+
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		gspiceui.1
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/gspiceui

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNGSPICE}
RUN_DEPENDS+=	ngspice:${PORTSDIR}/cad/ngspice_rework
.endif

.if ${PORT_OPTIONS:MGNUCAP}
RUN_DEPENDS+=	gnucap:${PORTSDIR}/cad/gnucap
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|:= -Ofast -pipe|+= -I.|g ; \
		 s|^INCLUDES |#INCLUDES |g ; \
		 s|$$(WXCFG)|$$(WX_CONFIG)|g ; \
		 s|$$(CC)|$$(CXX)|g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e \
		's|share/gspiceui|share/doc/gspiceui|g' ${WRKSRC}/src/main/HelpTasks.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gspiceui ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gspiceui.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONs:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for dir in html
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${DOCSDIR} \
		"! -name Makefile")
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for dir in lib sch
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${EXAMPLESDIR} \
		"! -name Makefile")
.endfor
.endif

.include <bsd.port.mk>
