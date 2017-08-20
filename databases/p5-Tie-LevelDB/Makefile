# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Tie-LevelDB
PORTVERSION=	0.07
PORTREVISION=	4
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl Interface to the Google LevelDB NoSQL database

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BROKEN_aarch64=	does not build: error: Please implement AtomicPointer for this platform
BROKEN_powerpc64=	does not build: error: unrecognized command line option -std=c++0x
BROKEN_sparc64=	does not build: unrecognized command line options

LIB_DEPENDS=	libleveldb.so:databases/leveldb

MAKE_ARGS=	CC="${CXX}"
USE_PERL5=	configure
USES=		compiler gmake localbase perl5

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-reserved-user-defined-literal
.endif

post-patch:
	@${REINPLACE_CMD} -e '/build_detect_platform/d' \
		-e 's|build_config.mk|${LOCALBASE}/share/leveldb/&|' \
		-e '/OBJECT/ s|".*\(LevelDB\.o\).*"|"\1"|' \
		-e 's|g++|${CXX}|' \
			${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Tie/LevelDB/LevelDB.so

.include <bsd.port.post.mk>
