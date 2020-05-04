# $FreeBSD$

PORTNAME=	elm
PORTVERSION=	0.19.1
CATEGORIES=	lang
MASTER_SITES=	LOCAL/arrowd/:package_list
DISTFILES=	elm-compiler-bootstrap-${PORTVERSION}${EXTRACT_SUFX}:package_list
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		elm-compiler-bootstrap-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Delightful language for reliable webapps

LICENSE=	BSD3CLAUSE

USES=		cabal

USE_GITHUB=	yes
GH_ACCOUNT=	elm
GH_PROJECT=	compiler

USE_CABAL=	ansi-terminal-0.8.2 \
		ansi-wl-pprint-0.6.8.2_2 \
		asn1-encoding-0.9.6_1 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		async-2.2.2_1 \
		attoparsec-0.13.2.4 \
		base-orphans-0.8.2 \
		basement-0.0.11_2 \
		binary-0.8.8.0 \
		blaze-builder-0.4.1.0 \
		bytestring-builder-0.10.8.2.0 \
		call-stack-0.2.0 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.1 \
		clock-0.8 \
		colour-2.3.5 \
		connection-0.3.1_1 \
		containers-0.5.11.0_3 \
		cookie-0.4.5 \
		cryptonite-0.26 \
		data-default-class-0.1.2.0 \
		digest-0.0.1.2 \
		edit-distance-0.2.2.1_1 \
		exceptions-0.10.4_1 \
		file-embed-0.0.11.2 \
		filelock-0.1.1.4 \
		hashable-1.3.0.0_1 \
		haskeline-0.8.0.0 \
		hourglass-0.2.12 \
		HTTP-4000.3.14_1 \
		http-client-0.6.4.1 \
		http-client-tls-0.3.5.3_1 \
		http-types-0.12.3 \
		HUnit-1.6.0.0 \
		integer-logarithms-1.0.3_2 \
		io-streams-1.5.1.0_1 \
		io-streams-haproxy-1.0.1.0_2 \
		language-glsl-0.3.0_1 \
		lifted-base-0.2.3.12 \
		memory-0.15.0_1 \
		mime-types-0.1.0.9 \
		monad-control-1.0.2.3 \
		network-2.6.3.6 \
		network-uri-2.6.3.0 \
		old-locale-1.0.0.7_2 \
		parsec-3.1.14.0_1 \
		pem-0.2.4 \
		prettyclass-1.0.0.0 \
		primitive-0.7.0.1 \
		random-1.1_1 \
		raw-strings-qq-1.1 \
		readable-0.3.1 \
		regex-base-0.94.0.0_1 \
		regex-posix-0.96.0.0_1 \
		scientific-0.3.6.2 \
		SHA-1.6.4.4 \
		snap-core-1.0.4.1 \
		snap-server-1.1.1.1_3 \
		socks-0.6.1 \
		streaming-commons-0.2.1.2 \
		text-1.2.4.0 \
		tls-1.5.4 \
		transformers-base-0.4.5.2 \
		transformers-compat-0.6.5 \
		unix-compat-0.5.2_1 \
		unordered-containers-0.2.10.0_1 \
		utf8-string-1.0.1.1_3 \
		vector-0.12.1.2 \
		x509-1.7.5_1 \
		x509-store-1.6.7_1 \
		x509-system-1.6.6 \
		x509-validation-1.6.11 \
		zip-archive-0.4.1_1 \
		zlib-0.6.2.1_1 \
		zlib-bindings-0.1.1.5_2

MAKE_ENV=	ELM_HOME=${WRKDIR}/elm-compiler-bootstrap-${PORTVERSION}

post-extract:
	${RM} ${WRKSRC}/worker/elm.cabal

.PHONY: create-bootstrap
# Create the bootstrapping elm packages and registry files
# This is needed because it builds the reactor app, which is written in elm!
create-bootstrap:
	# Prepare source
	${MKDIR} ${WRKDIR}
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}_GH${_GITHUB_REV}${EXTRACT_SUFX} -C ${WRKDIR}
	${RM} ${WRKSRC}/worker/elm.cabal
	# Build with a custom home
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} HOME=${CABAL_HOME} cabal new-update && \
		${SETENV} ${MAKE_ENV} HOME=${CABAL_HOME} cabal new-build --disable-benchmarks --disable-tests --flags ${CABAL_FLAGS} ${BUILD_ARGS} ${BUILD_TARGET}
	# Prepare the bootstrap to /tmp
	${TAR} --numeric-owner -czf /tmp/elm-compiler-bootstrap-${PORTVERSION}${EXTRACT_SUFX} -C ${WRKDIR} \
		elm-compiler-bootstrap-${PORTVERSION}
	# Now all that's left is manually placing the bootstrap file in ${DISTDIR}/cabal/
	# And running make makesum to update the distfile

.include <bsd.port.mk>
