# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scala-ide
DISTVERSION=	3.0.1-RC2
CATEGORIES=	devel java
MASTER_SITES=	http://download.scala-ide.org/sdk/e37/scala210/dev/
DISTNAME=	update-site
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}-20130628

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Scala plugin for the Eclipse IDE

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/site

.include "${.CURDIR}/../../java/eclipse/Makefile.plugins"

.include <bsd.port.mk>
