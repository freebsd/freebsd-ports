# Created by: Tim Bishop <tdb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	superdatetime
PORTVERSION=	5.9.16
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	squeezeboxserver-
DISTNAME=	SuperDateTime${PORTVERSION}
DIST_SUBDIR=	squeezeboxserver

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Squeezebox Server plugin to display weather conditions and forecasts

RUN_DEPENDS=	softsqueeze:audio/squeezeboxserver

PROJECTHOST=	grebrown-projects

USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

SLIMDIR?=	squeezeboxserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/SuperDateTime
	${CP} -R ${WRKSRC}/SuperDateTime/* ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/SuperDateTime

.include <bsd.port.mk>
