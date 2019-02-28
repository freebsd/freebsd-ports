# $FreeBSD$

PORTNAME=	libdill
DISTVERSION=	2.14
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Structured concurrency library in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	error: this directive must appear between .cfi_startproc and .cfi_endproc directives

USES=		autoreconf gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_GITHUB=	yes
GH_ACCOUNT=	sustrik
USE_LDCONFIG=	yes

.include <bsd.port.mk>
