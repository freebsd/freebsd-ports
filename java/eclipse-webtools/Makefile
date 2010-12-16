# New ports collection makefile for:	eclipse-webtools
# Date created:				October 14, 2005
# Whom:					markhobden@gmail.com
#
# $FreeBSD$
#

PORTNAME=	webtools
PORTVERSION=	3.2.2
CATEGORIES=	java devel www
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/webtools/downloads/drops/,}
MASTER_SITE_SUBDIR=	R3.2.2/R-${PORTVERSION}-20100915173744
PKGNAMEPREFIX=	eclipse-
DISTNAME=	wtp-R-${PORTVERSION}-20100915173744
DIST_SUBDIR=	eclipse

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	Webtools for eclipse

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/share/eclipse/dropins/emf:${PORTSDIR}/java/eclipse-emf \
		${LOCALBASE}/share/eclipse/dropins/gef:${PORTSDIR}/java/eclipse-gef

WRKSRC=		${WRKDIR}/eclipse
USE_ZIP=	yes

OPTIONS=	DTP "Enable support for EJB and JPT development" on

.include <bsd.port.options.mk>

.if defined(WITH_DTP)
RUN_DEPENDS+=	${LOCALBASE}/share/eclipse/dropins/datatools:${PORTSDIR}/java/eclipse-datatools
.endif

.include "${.CURDIR}/../eclipse/Makefile.plugins"

.include <bsd.port.mk>
