PORTNAME=	mupen64plus
PORTVERSION?=	2.6.0.${RELEASE_DATE}
PORTREVISION?=	0
CATEGORIES=	emulators
PKGNAMESUFFIX?=	-core
DIST_SUBDIR=	${PORTNAME}

MAINTAINER?=	acm@FreeBSD.org
COMMENT?=	Fork of Mupen64 Nintendo 64 emulator
WWW=		https://www.mupen64plus.org/

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}
GH_TAGNAME?=	b0d68c20f49b8f833afa21450e0e8874c87c13c4

USES+=		gl gmake pkgconfig sdl
USE_GL?=	glu
USE_SDL?=	sdl2
USE_LDCONFIG?=	yes
ONLY_FOR_ARCHS=	i386 amd64

RELEASE_DATE?=	20240714
OPTFLAGS=	#

MAKE_ENV+=	OPTFLAGS="${OPTFLAGS}"

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/../mupen64plus-core/Makefile.common"
.include <bsd.port.mk>
