# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	nekobee
PORTVERSION=	0.1.8
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	GH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DSSI plugin that emulates the sound of the TB-303 Bassline

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:${PORTSDIR}/audio/dssi
LIB_DEPENDS=	dssialsacompat:${PORTSDIR}/audio/libdssialsacompat \
		lo:${PORTSDIR}/audio/liblo \
		jack:${PORTSDIR}/audio/jack

USE_GITHUB=	yes
GH_ACCOUNT=	gordonjcp
GH_COMMIT=	3f4737f

USE_GNOME=	gtk20
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include/dssi -I${LOCALBASE}/include

.if !defined(DISABLE_MAKE_JOBS)
MAKE_JOBS_ARGS=	-j${MAKE_JOBS_NUMBER}
.endif

do-configure:
	@(cd ${WRKSRC} && ${SETENV} CC="${CC}" CFLAGS="${CFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" ./waf configure --prefix=${PREFIX})

do-build:
	@(cd ${WRKSRC} && ./waf build -vvv ${MAKE_JOBS_ARGS})

do-install:
	@(cd ${WRKSRC} && ./waf install)

.include <bsd.port.mk>
