PORTNAME=	gpxloggerd
PORTVERSION=	0.2.5
PORTREVISION=	2
CATEGORIES=	astro

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Daemon that connects to the GPSD daemon and logs GPS traces
WWW=		https://github.com/glebius/gpxloggerd

FLAVORS=	x11 nox11
FLAVOR?=	${FLAVORS:[1]}
nox11_PKGNAMESUFFIX=	-nox11

nox11_LIB_DEPENDS=	libgps.so:astro/gpsd@nox11
x11_LIB_DEPENDS=	libgps.so:astro/gpsd

USE_GITHUB=	yes
GH_ACCOUNT=	glebius
USE_RC_SUBR=	${PORTNAME}

LDFLAGS+=	-lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8/

PLIST_FILES=	sbin/${PORTNAME} \
		share/man/man8/${PORTNAME}.8.gz

.include <bsd.port.mk>
