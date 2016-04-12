# Created by: Tim Bishop <tdb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	trackstat
PORTVERSION=	2.11.3435
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://erland.isaksson.info/download/do/downloadapplication?name=slimserver-trackstat&filename=/
PKGNAMEPREFIX=	squeezeboxserver-
DISTNAME=	TrackStat-${PORTVERSION:S/b/beta/}
DIST_SUBDIR=	squeezeboxserver

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Squeezebox Server plugin to store ratings and statistics about songs

RUN_DEPENDS=	softsqueeze:audio/squeezeboxserver

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

SLIMDIR?=	squeezeboxserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/TrackStat
	${CP} -R ${WRKSRC}/TrackStat/* ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/TrackStat

.include <bsd.port.mk>
