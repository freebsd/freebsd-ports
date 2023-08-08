PORTNAME=	sherlock
DISTVERSION=	0.28.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://git.open-music-kontrollers.ch/lv2/sherlock.lv2/snapshot/
PKGNAMESUFFIX=	-lv2
DISTNAME=	${PORTNAME}.lv2-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Investigative LV2 plugin bundle
WWW=		https://open-music-kontrollers.ch/lv2/sherlock/

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom

USES=		compiler:c11 gl meson pkgconfig tar:xz xorg
USE_XORG=	x11 xext
USE_GL=		gl glew glu

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
