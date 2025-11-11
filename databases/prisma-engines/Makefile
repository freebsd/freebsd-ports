PORTNAME=	prisma-engines
DISTVERSION=	6.19.0
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Engines for Prisma stack
WWW=		https://github.com/prisma/prisma-engines

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	prisma

MAKE_ENV=	CARGO_PROFILE_RELEASE_LTO=thin \
		GIT_HASH=${DISTVERSION} \
		OPENSSL_INCLUDE_DIR=${OPENSSLINC} \
		OPENSSL_LIB_DIR=${OPENSSLLIB}

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
		@${ECHO} "@dir libexec/${PORTNAME}" >> ${TMPPLIST}
.for f in libquery_engine.so prisma-fmt query-engine schema-engine
		${INSTALL_PROGRAM} ${WRKDIR}/target/release/$f ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
		@${ECHO} "libexec/${PORTNAME}/$f" >> ${TMPPLIST}
.endfor

.include <bsd.port.mk>
