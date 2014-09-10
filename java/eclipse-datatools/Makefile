# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	datatools
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	java devel databases
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/,}
MASTER_SITE_SUBDIR=datatools/downloads/${PORTVERSION}
PKGNAMEPREFIX=	eclipse-
DISTNAME=	dtp-sdk_${PORTVERSION}.0
DIST_SUBDIR=	eclipse

MAINTAINER=	ljboiler@gmail.com
COMMENT=	Data Tools Platform for the Eclipse IDE

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/share/eclipse/dropins/emf:${PORTSDIR}/java/eclipse-emf \
		${LOCALBASE}/share/eclipse/dropins/gef:${PORTSDIR}/java/eclipse-gef

LICENSE=	EPL

WRKSRC=		${WRKDIR}/eclipse
USES=		zip

.include "${.CURDIR}/../eclipse/Makefile.plugins"

.include <bsd.port.mk>
