PORTNAME=	chiapos
DISTVERSION=	1.0.3
CATEGORIES=	finance
MASTER_SITES=	CHEESESHOP
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	risner@stdio.com
COMMENT=	Chia proof of space plotting, proving, and verifying (cmake part)

LICENSE=	APACHE20 BSD2CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/lib/FiniteStateEntropy/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/MIT-LICENSES
LICENSE_DISTFILES_APACHE20=	${DISTNAME}${EXTRACT_SUFX}
LICENSE_DISTFILES_BSD2CLAUSE=	${DISTNAME}${EXTRACT_SUFX}
LICENSE_DISTFILES_MIT=		${DISTNAME}${EXTRACT_SUFX} ${DISTFILE_c} \
				${DISTFILE_g}

NOT_FOR_ARCHS=	i386 powerpc

USES=		cmake:noninja
USE_GITHUB=	nodefault
GH_TUPLE=	jarro2783:cxxopts:302302b30839505703d37fb82f536c53cf9172fa:c/src-ext/cxxopts \
		gulrak:filesystem:4e21ab305794f5309a1454b4ae82ab9a0f5e0d25:g/src-ext/gulrak
CMAKE_ARGS+=	-DCOMPILER_CXXFLAGS="${CXXFLAGS}" \
		-DCOMPILER_FLAGS="${CFLAGS}"
PLIST_FILES=	bin/ProofOfSpace \
		bin/RunTests

post-extract:
# This example is experimental, currently broken (upstream) and unnecessary.
# The placeholder Makefile is for when/if they release a future fixed version.
	@${CP} ${FILESDIR}/Hellman-Makefile ${WRKSRC}/hellman_example/Makefile
# Remove extraneous unused files to prevent confusion
	@${RM} ${WRKSRC}/lib/FiniteStateEntropy/fetch-content-CMakeLists.txt
	@${RM} ${WRKSRC}/pyproject.toml
# Concatenate the MIT licenses
	@( ${ECHO_MSG} "uint128_t license:"; \
		${CAT} ${WRKSRC}/uint128_t/LICENSE; \
		${ECHO_MSG} ""; ${ECHO_MSG} ""; \
		${ECHO_MSG} "cxxopts license:"; \
		${CAT} ${WRKSRC}/src-ext/cxxopts/LICENSE; \
		${ECHO_MSG} ""; ${ECHO_MSG} ""; \
		${ECHO_MSG} "gulrak license:"; \
		${CAT} ${WRKSRC}/src-ext/gulrak/LICENSE ) \
			> ${WRKSRC}/MIT-LICENSES

do-test: stage
	${WRKDIR}/.build/RunTests

.include <bsd.port.mk>
