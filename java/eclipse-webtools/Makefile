# Created by: markhobden@gmail.com
# $FreeBSD$

PORTNAME=	webtools
PORTVERSION=	3.5.2
PORTREVISION=	1
CATEGORIES=	java devel www
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/,}
MASTER_SITE_SUBDIR=webtools/downloads/drops/R${PORTVERSION}/R-${PORTVERSION}-20140217150812
PKGNAMEPREFIX=	eclipse-
DISTNAME=	wtp4x-R-${PORTVERSION}-20140217150812
DIST_SUBDIR=	eclipse

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Webtools for eclipse

LICENSE=	EPL

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse \
		eclipse-emf>0:${PORTSDIR}/java/eclipse-emf \
		eclipse-gef>0:${PORTSDIR}/java/eclipse-gef \
		eclipse-datatools>0:${PORTSDIR}/java/eclipse-datatools

WRKSRC=		${WRKDIR}/eclipse
USES=		zip

.include "${.CURDIR}/../eclipse/Makefile.plugins"

.include <bsd.port.mk>
