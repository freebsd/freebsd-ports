# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scala-ide
DISTVERSION=	3.0.4
PORTREVISION=	1
CATEGORIES=	devel java
#MASTER_SITES=	http://download.scala-ide.org/sdk/e37/scala210/dev/
MASTER_SITES=	http://download.scala-ide.org/sdk/helium/e38/scala211/stable/
DISTNAME=	update-site
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Scala plugin for the Eclipse IDE

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

OPTIONS_DEFINE=	WTP
OPTIONS_DEFAULT=WTP
WTP_DESC=	Install Eclipse Web Tools Platform (required for Play2 plug-in)

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/site

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWTP}
RUN_DEPENDS+=	${LOCALBASE}/share/eclipse/dropins/webtools:${PORTSDIR}/java/eclipse-webtools
.endif

.include "${.CURDIR}/../../java/eclipse/Makefile.plugins"

.include <bsd.port.mk>
