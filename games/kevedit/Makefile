PORTNAME=	kevedit
PORTVERSION=	0.5.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern ZZT editor with necessary features
WWW=		https://github.com/cknave/kevedit

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	cdrecord:sysutils/cdrtools
RUN_DEPENDS=	cdrecord:sysutils/cdrtools

USES=		sdl
USE_SDL=	sdl

GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
