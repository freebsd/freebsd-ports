# Created by: olgeni@FreeBSD.org
# $FreeBSD$

PORTNAME=	gef
PORTVERSION=	3.7.2
CATEGORIES=	java devel
MASTER_SITES=	http://archive.eclipse.org/tools/gef/downloads/drops/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}/R201201171043
PKGNAMEPREFIX=	eclipse-
DISTNAME=	GEF-ALL-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	Graphical Editing Framework for the Eclipse IDE

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

WRKSRC=		${WRKDIR}/eclipse
USES=		zip

.include "${.CURDIR}/../eclipse/Makefile.plugins"

.include <bsd.port.mk>
