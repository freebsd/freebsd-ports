PORTNAME=	cim
PORTVERSION=	3.37
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	http://simula67.at.ifi.uio.no/Cim/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Compiler for the SIMULA programming language
WWW=		http://folk.uio.no/simula67/cim.shtml

LICENSE=	GPLv2

USES=		libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INSTALL_TARGET=	install-strip
TEST_TARGET=	check-TESTS

TEST_WRKSRC=	${WRKSRC}/test

INFO=		cim

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
