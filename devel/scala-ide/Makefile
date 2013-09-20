# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scala-ide
DISTVERSION=	3.0.1
CATEGORIES=	devel java
MASTER_SITES=	http://download.scala-ide.org/sdk/e37/scala210/dev/
DISTNAME=	update-site
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}-20130802

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Scala plugin for the Eclipse IDE

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

OPTIONS_DEFINE=	WTP
OPTIONS_DEFAULT=WTP
WTP_DESC=	Install Eclipse Web Tools Platform (required for Play2 plug-in)

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/site

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWTP}
RUN_DEPENDS+=	${LOCALBASE}/share/eclipse/dropins/webtools:${PORTSDIR}/java/eclipse-webtools
.endif

.include "${.CURDIR}/../../java/eclipse/Makefile.plugins"

.include <bsd.port.mk>
