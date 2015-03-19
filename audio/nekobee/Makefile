# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	nekobee
PORTVERSION=	0.1.8
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	GHL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DSSI plugin that emulates the sound of the TB-303 Bassline

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:${PORTSDIR}/audio/dssi
LIB_DEPENDS=	libdssialsacompat.so:${PORTSDIR}/audio/libdssialsacompat \
		liblo.so:${PORTSDIR}/audio/liblo \
		libjack.so:${PORTSDIR}/audio/jack

USE_GITHUB=	yes
GH_ACCOUNT=	gordonjcp
GH_COMMIT=	3f4737f

USES=		pkgconfig
USE_GNOME=	gtk20

CPPFLAGS+=	-I${LOCALBASE}/include/dssi -I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e \
		'/LINKFLAGS/s|^|#|' ${WRKSRC}/wscript

do-configure:
	@(cd ${WRKSRC} && ${SETENV} CC="${CC}" CFLAGS="${CFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" LINKFLAGS="-lm" \
		 ./waf configure --prefix=${PREFIX})

do-build:
	@(cd ${WRKSRC} && ./waf build -vvv -j${MAKE_JOBS_NUMBER})

do-install:
	@(cd ${WRKSRC} && ./waf install --destdir=${STAGEDIR})
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dssi/nekobee.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dssi/nekobee/nekobee_gtk

.include <bsd.port.mk>
