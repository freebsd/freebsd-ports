# Created by: olgeni@FreeBSD.org
# $FreeBSD$

PORTNAME=	gef
PORTVERSION=	3.9.100
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/,}
MASTER_SITE_SUBDIR=tools/gef/downloads/drops/${PORTVERSION}/R201405261516

PKGNAMEPREFIX=	eclipse-
DISTNAME=	GEF-ALL-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	Graphical Editing Framework for the Eclipse IDE

BROKEN=		plugin is obsolete or malfunctioning with latest eclipse
DEPRECATED=	evaluation recommendation is to remove rather than update
EXPIRATION_DATE=	2015-04-18

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

WRKSRC=		${WRKDIR}/eclipse
USES=		zip

.include "${.CURDIR}/../eclipse/Makefile.plugins"

.include <bsd.port.mk>
