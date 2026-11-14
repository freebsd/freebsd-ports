PORTNAME=	qdrant
DISTVERSIONPREFIX=	v
DISTVERSION=	1.20.1
PORTEPOCH=	1
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Vector search engine and database for the next gen AI applications
WWW=		https://qdrant.tech \
		https://github.com/qdrant/qdrant

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compiler crashes, see https://github.com/rust-lang/rust/issues/120637
BROKEN_i386=	compilation breaks with fatal warning: implicit conversion from 'std::numeric_limits<unsigned long long>::type' (aka 'unsigned long long') to 'size_t' (aka 'unsigned int') changes value from 18446744073709551615 to 4294967295

BUILD_DEPENDS=	protoc:devel/protobuf
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo cpe gmake llvm:min=13 perl5 pkgconfig
USE_GITHUB=	yes

# aws-lc-sys's jitterentropy must be built with -O0, but ports CFLAGS adds -O2
# which overrides it. Disable jitterentropy; the system RNG is still used.
MAKE_ENV+=	AWS_LC_SYS_NO_JITTER_ENTROPY=1

USE_PERL5=	build
USE_RC_SUBR=	qdrant

QDRANT_DBDIR?=	/var/db/qdrant
QDRANT_USER?=	nobody
QDRANT_GROUP?=	nobody

SUB_LIST=	RC_SUBR_SUFFIX=${RC_SUBR_SUFFIX}

PLIST_SUB=	QDRANT_DBDIR=${QDRANT_DBDIR} \
		QDRANT_GROUP=${QDRANT_GROUP} \
		QDRANT_USER=${QDRANT_USER}

post-patch:
	${REINPLACE_CMD} -e "s,%%DBDIR%%,${QDRANT_DBDIR},g; \
		s,%%ETCDIR%%,${ETCDIR},g" ${WRKSRC}/config/config.yaml

post-install:
# install config sample
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}/tls
	${MKDIR} ${STAGEDIR}${QDRANT_DBDIR}
	${INSTALL_DATA} ${WRKSRC}/config/config.yaml ${STAGEDIR}${ETCDIR}/config.yaml.sample

.include <bsd.port.mk>
