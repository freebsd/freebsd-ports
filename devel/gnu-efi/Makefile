# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnu-efi
PORTVERSION=	3.0.3
CATEGORIES=	devel
MASTER_SITES=	SF/gnu-efi

MAINTAINER=	ports@toco-domains.de
COMMENT=	SDK for EFI applications

LICENSE=	GPLv2

BUILD_DEPENDS+=	${LOCALBASE}/bin/ar:devel/binutils

USES=		gmake tar:bz2
USE_GCC=	yes
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=	"-fPIC"
CPPFLAGS+=	"-fPIC"
MAKE_ARGS+=	CC=${CC} HOSTCC=${CC} AR=${AR}
ONLY_FOR_ARCHS=	amd64

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/crt0-efi-x86_64.o

.include <bsd.port.mk>
