PORTNAME=	cim
PORTVERSION=	3.37
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://simula67.at.ifi.uio.no/Cim/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Compiler for the SIMULA programming language
WWW=		http://folk.uio.no/simula67/cim.shtml

LICENSE=	GPLv2

USES=		libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check-TESTS

TEST_WRKSRC=	${WRKSRC}/test

INFO=		cim

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
