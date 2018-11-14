# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnu-efi
PORTVERSION=	3.0.9
CATEGORIES=	devel
MASTER_SITES=	SF/gnu-efi

MAINTAINER=	egypcio@googlemail.com
COMMENT=	SDK for EFI applications

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS+=	${LOCALBASE}/bin/ar:devel/binutils

USES=		compiler:c++11-lib gmake tar:bz2

CFLAGS+=	-fPIC
CPPFLAGS+=	-fPIC
MAKE_ARGS+=	CC=${CC} HOSTCC=${CC} AR=${AR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/crt0-efi-x86_64.o

.include <bsd.port.mk>
