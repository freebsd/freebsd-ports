# Created by: Tim Bishop <tdb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	trackstat
PORTVERSION=	3.2.3951
CATEGORIES=	audio
MASTER_SITES=	http://downloads.isaksson.info/download/do/downloadapplication?name=slimserver-trackstat&filename=/
PKGNAMEPREFIX=	logitechmediaserver-
DISTNAME=	TrackStat-${PORTVERSION:S/b/beta/}
DIST_SUBDIR=	logitechmediaserver

MAINTAINER=	mark@tranquillussoftware.co.uk
COMMENT=	Logitech Media Server plugin to store song ratings and statistics

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/TrackStat/LICENSE.txt

RUN_DEPENDS=	${LOCALBASE}/${SLIMDIR}/slimserver.pl:audio/logitechmediaserver

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

SLIMDIR?=	share/logitechmediaserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/TrackStat
	${CP} -R ${WRKSRC}/TrackStat/* ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/TrackStat

.include <bsd.port.mk>
