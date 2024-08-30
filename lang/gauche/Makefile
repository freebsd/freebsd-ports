PORTNAME=	gauche
PORTVERSION=	0.9.15
CATEGORIES=	lang scheme
MASTER_SITES=	https://github.com/shirok/Gauche/releases/download/release${PORTVERSION:S/./_/g}/
DISTNAME=	Gauche-${PORTVERSION}

MAINTAINER=	lassi+freebsd@lassi.io
COMMENT=	Scheme script interpreter with multibyte character handling
WWW=		https://practical-scheme.net/gauche/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_mips=	Fails to build: redefinition of GC_register_dynamic_libraries
BROKEN_mips64=	Fails to build: redefinition of GC_register_dynamic_libraries
BROKEN_riscv64=	Fails to build: ./include/private/gcconfig.h:709:5: The collector has not been ported to this machine/OS combination

USES=		compiler:c11 cpe gmake iconv makeinfo tar:tgz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-local=${LOCALBASE} ${ICONV_CONFIGURE_BASE:S/lib//}
USE_LDCONFIG=	yes
TEST_TARGET=	check
ABI_VERSION=	0.98

PLIST_SUB=	ABI_VERSION="${ABI_VERSION}" \
		VERSION="${PORTVERSION}" \
		TARGET="${CONFIGURE_TARGET}"

# Avoid the problem with ccache's pre-processor optimization
MAKE_ENV+=	CCACHE_CPP2=1
TEST_ENV=	# must be empty, otherwise cf-check-lib test fails

INFO=		gauche-refe gauche-refj

OPTIONS_DEFINE=		GDBM SLIB TLS
OPTIONS_DEFAULT=	TLS
OPTIONS_SUB=		yes

GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_ON=	--with-dbm=gdbm,ndbm
GDBM_CONFIGURE_OFF=	--with-dbm=ndbm

TLS_LIB_DEPENDS=	libmbedtls.so:security/mbedtls
TLS_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
TLS_CONFIGURE_ON=	--with-ca-bundle=${LOCALBASE}/share/certs/ca-root-nss.crt
TLS_CONFIGURE_OFF=	--with-tls=no

# Gauche's slib module to use Aubrey Jaffer's SLIB
SLIB_DESC=		Create catalogue for SLIB port
SLIB_BUILD_DEPENDS=	${LOCALBASE}/share/slib/require.scm:lang/slib
SLIB_CONFIGURE_ON=	--with-slib=${LOCALBASE}/share/slib
SLIB_CONFIGURE_OFF=	--with-slib=${WRKDIR}

post-patch:
# unbreak "make test" by using the same workaround as for OSX (darwin),
# apparently because we both use clang (XXX: what about gcc?)
	@${REINPLACE_CMD} -e \
		's,darwin,&|${OPSYS:tl},' ${WRKSRC}/test/scripts.scm

post-install:
	@${TOUCH} ${STAGEDIR}${PREFIX}/lib/gauche-${ABI_VERSION}/site/${CONFIGURE_TARGET}/.keepme
	@${MKDIR} ${STAGEDIR}${DATADIR}/${PORTVERSION}/lib/.packages
	@${TOUCH} ${STAGEDIR}${DATADIR}/${PORTVERSION}/lib/.packages/.keepme
	@${MKDIR} ${STAGEDIR}${DATADIR}/site/lib/.packages
	@${TOUCH} ${STAGEDIR}${DATADIR}/site/lib/.packages/.keepme
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gauche-${ABI_VERSION}/site/lib/.packages
	@${TOUCH} ${STAGEDIR}${PREFIX}/share/gauche-${ABI_VERSION}/site/lib/.packages/.keepme
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${TOUCH} ${STAGEDIR}${DOCSDIR}/.keepme
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${TOUCH} ${STAGEDIR}${EXAMPLESDIR}/.keepme
.for i in gauche-config gosh
	@${CHMOD} u+w ${STAGEDIR}${PREFIX}/bin/${i}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
	@${CHMOD} u-w ${STAGEDIR}${PREFIX}/bin/${i}
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgauche-${ABI_VERSION}.so.[0-9].*
.for i in gauche-config gosh *.so
	@${CHMOD} u+w ${STAGEDIR}${PREFIX}/lib/gauche-${ABI_VERSION}/${PORTVERSION}/${CONFIGURE_TARGET}/${i}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gauche-${ABI_VERSION}/${PORTVERSION}/${CONFIGURE_TARGET}/${i}
	@${CHMOD} u-w ${STAGEDIR}${PREFIX}/lib/gauche-${ABI_VERSION}/${PORTVERSION}/${CONFIGURE_TARGET}/${i}
.endfor

.include <bsd.port.mk>
