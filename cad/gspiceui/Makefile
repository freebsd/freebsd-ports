# New ports collection makefile for:	gspiceui
# Date created:		30 April 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	gspiceui
PORTVERSION=	0.9.65
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	GUI frontend for gnucap/ng-spice circuit simulators

RUN_DEPENDS=	gwave:${PORTSDIR}/cad/gwave

USE_WX=		2.6+
WX_UNICODE=	yes
USE_GMAKE=	yes

OPTIONS=	NGSPICE "Use ng-spice as backend" on \
		GNUCAP "Use gnucap as backend" off \
		MODELS "Install example models" on

PORTDOCS=	*

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -E -e "s,%%WX_CONFIG%%,${WX_CONFIG},g" \
		${WRKSRC}/src/Makefile

.if !defined(WITHOUT_NGSPICE)
RUN_DEPENDS+=	ngspice:${PORTSDIR}/cad/ngspice_rework
.endif

.if defined(WITH_GNUCAP)
RUN_DEPENDS+=	gnucap:${PORTSDIR}/cad/gnucap
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/html && ${COPYTREE_SHARE} \* ${DOCSDIR} \
		"! -name Makefile")
.endif
.if !defined(WITHOUT_MODELS)
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} sch ${DATADIR} \
		"! -name Makefile" && \
		${COPYTREE_SHARE} lib ${DATADIR} "! -name Makefile")
PLIST_SUB+=	MODELS=""
.else
PLIST_SUB+=	MODELS="@comment "
.endif

.include <bsd.port.post.mk>
