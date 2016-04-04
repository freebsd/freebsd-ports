# Created by: Gleb Smirnoff <glebius@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gpxloggerd
PORTVERSION=	0.2.3
CATEGORIES=	astro
USE_GITHUB=	yes
GH_ACCOUNT=	glebius

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Daemon that connects to the GPSD daemon and logs GPS traces

LIB_DEPENDS=	libgps.so:astro/gpsd

USE_RC_SUBR=	${PORTNAME}
PLIST_FILES=	sbin/${PORTNAME} \
		man/man8/${PORTNAME}.8.gz

LDFLAGS+=	-lm
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_ARGS=	NO_WERROR=yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/man/man8/

.include <bsd.port.mk>
