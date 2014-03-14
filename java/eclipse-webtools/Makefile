# Created by: markhobden@gmail.com
# $FreeBSD$

PORTNAME=	webtools
PORTVERSION=	3.3.2
CATEGORIES=	java devel www
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/webtools/downloads/drops/,}
MASTER_SITE_SUBDIR=	R${PORTVERSION}/R-${PORTVERSION}-20120210195245
PKGNAMEPREFIX=	eclipse-
DISTNAME=	wtp-R-${PORTVERSION}-20120210195245
DIST_SUBDIR=	eclipse

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Webtools for eclipse

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/share/eclipse/dropins/emf:${PORTSDIR}/java/eclipse-emf \
		${LOCALBASE}/share/eclipse/dropins/gef:${PORTSDIR}/java/eclipse-gef \
		${LOCALBASE}/share/eclipse/dropins/datatools:${PORTSDIR}/java/eclipse-datatools

WRKSRC=		${WRKDIR}/eclipse
USES=		zip

NO_STAGE=	yes
.include "${.CURDIR}/../eclipse/Makefile.plugins"

.include <bsd.port.mk>
