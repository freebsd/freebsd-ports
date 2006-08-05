# New ports collection makefile for:	gspiceui
# Date created:		30 April 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	gspiceui
PORTVERSION=	0.8.55
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	GUI frontend for gnucap/ng-spice circuit simulators

LIB_DEPENDS=	wx_gtk2u_core-2.6:${PORTSDIR}/x11-toolkits/wxgtk26-unicode
RUN_DEPENDS=	gwave:${PORTSDIR}/cad/gwave

USE_X_PREFIX=	yes
USE_GMAKE=	yes

OPTIONS=	NGSPICE "Use ng-spice as backend" on \
		GNUCAP "Use gnucap as backend" off \
		MODELS "Install example models" on

PORTDOCS=	*

# XXX: exists untill it will be committed to bsd.port.mk
COPYTREE_SHARE=	${SH} -c '(${FIND} -d $$0 $$2 | ${CPIO} -dumpl $$1 >/dev/null \
		2>&1) && \
		${CHOWN} -R ${SHAREOWN}:${SHAREGRP} $$1 && \
		${FIND} $$1/ -type d -exec ${CHMOD} 755 {} \; && \
		${FIND} $$1/ -type f -exec ${CHMOD} ${SHAREMODE} {} \;' --

.include <bsd.port.pre.mk>

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
