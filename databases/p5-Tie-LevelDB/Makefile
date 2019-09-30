# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Tie-LevelDB
PORTVERSION=	0.07
PORTREVISION=	6
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl Interface to the Google LevelDB NoSQL database

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

NOT_FOR_ARCHS=		aarch64 powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	does not build: Please implement AtomicPointer for this platform
BROKEN_sparc64=	does not build: unrecognized command line options

LIB_DEPENDS=	libleveldb.so:databases/leveldb

USES=		compiler:c++11-lang gmake localbase perl5
USE_PERL5=	configure

CFLAGS_powerpc=	-DLEVELDB_CSTDATOMIC_PRESENT
CFLAGS_powerpc64=	-DLEVELDB_CSTDATOMIC_PRESENT
CFLAGS_powerpcspe=	-DLEVELDB_CSTDATOMIC_PRESENT
MAKE_ARGS=	CC="${CXX}"

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
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
