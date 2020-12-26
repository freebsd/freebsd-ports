# $FreeBSD$

PORTNAME=	basu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0-40
DISTVERSIONSUFFIX=	-g5263cc0
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	sd-bus library, extracted from systemd

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL2.1

USES=		compiler:c11 gperf meson python:build shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	emersion
SHEBANG_FILES=	src/basic/generate-gperfs.py

.if exists(/usr/bin/ld.lld) && ${/usr/bin/ld:L:tA} != /usr/bin/ld.lld
# bus-error.c:(.text.bus_error_name_to_errno+0x9a): undefined reference to '__start_BUS_ERROR_MAP'
LDFLAGS+=	-fuse-ld=lld
.endif

.include <bsd.port.mk>
