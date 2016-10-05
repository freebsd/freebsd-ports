# Created by: Tim Bishop <tdb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	superdatetime
PORTVERSION=	5.9.16
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	grebrown-projects
PKGNAMEPREFIX=	logitechmediaserver-
DISTNAME=	SuperDateTime${PORTVERSION}
DIST_SUBDIR=	logitechmediaserver

MAINTAINER=	mark@tranquillussoftware.co.uk
COMMENT=	Logitech Media Server plugin to display weather conditions & forecasts

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BROKEN=		Unfetchable (google code has gone away)

RUN_DEPENDS=	${LOCALBASE}/${SLIMDIR}/slimserver.pl:audio/logitechmediaserver

USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

SLIMDIR?=	share/logitechmediaserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/SuperDateTime
	${CP} -R ${WRKSRC}/SuperDateTime/* ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/SuperDateTime

.include <bsd.port.mk>
