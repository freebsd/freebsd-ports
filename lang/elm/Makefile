PORTNAME=	elm
PORTVERSION=	0.19.1
PORTREVISION=	8
CATEGORIES=	lang
MASTER_SITES=	LOCAL/arrowd/:package_list
DISTFILES=	elm-compiler-bootstrap-${PORTVERSION}${EXTRACT_SUFX}:package_list

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Delightful language for reliable webapps
WWW=		https://elm-lang.org/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ghc-9.2.8:lang/ghc92

USES=		cabal nodejs:run

USE_GITHUB=	yes
GH_ACCOUNT=	elm
GH_PROJECT=	compiler

CONFLICTS_INSTALL=	elm # bin/elm (from mail/elm)

USE_CABAL=	HTTP-4000.4.1_6 \
		HUnit-1.6.2.0 \
		SHA-1.6.4.4 \
		ansi-terminal-1.0.2 \
		ansi-terminal-types-0.11.5_1 \
		ansi-wl-pprint-0.6.9_4 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.1.1_1 \
		async-2.2.5_3 \
		attoparsec-0.14.4_6 \
		base-orphans-0.9.3 \
		base16-bytestring-1.0.2.0_1 \
		base64-bytestring-1.2.1.0_1 \
		basement-0.0.16 \
		blaze-builder-0.4.3 \
		byteorder-1.0.4 \
		bytestring-builder-0.10.8.2.0 \
		call-stack-0.4.0 \
		case-insensitive-1.2.1.0 \
		cborg-0.2.10.0_2 \
		cereal-0.5.8.3 \
		clock-0.8.4 \
		colour-2.3.6 \
		cookie-0.5.1 \
		crypton-1.0.4 \
		crypton-connection-0.4.4 \
		crypton-x509-1.7.7 \
		crypton-x509-store-1.6.10 \
		crypton-x509-system-1.6.7 \
		crypton-x509-validation-1.6.14 \
		data-array-byte-0.1.0.1_4 \
		data-default-0.8.0.1 \
		data-default-class-0.2.0.0 \
		digest-0.0.2.1 \
		ech-config-0.0.1 \
		edit-distance-0.2.2.1_1 \
		file-embed-0.0.16.0 \
		filelock-0.1.1.7 \
		foldable1-classes-compat-0.1.1_2 \
		half-0.3.2 \
		hashable-1.4.7.0 \
		hourglass-0.2.12_1 \
		hpke-0.0.0 \
		hsc2hs-0.68.10_4 \
		http-client-0.7.19 \
		http-client-tls-0.3.6.4_2 \
		http-types-0.12.4 \
		integer-logarithms-1.0.4 \
		io-streams-1.5.2.2_6 \
		io-streams-haproxy-1.0.1.0_9 \
		iproute-1.7.15 \
		language-glsl-0.3.0_1 \
		lifted-base-0.2.3.12 \
		memory-0.18.0_1 \
		mime-types-0.1.2.0 \
		monad-control-1.0.3.1 \
		network-3.2.7.0 \
		network-byte-order-0.1.7 \
		network-uri-2.6.4.2_1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.4 \
		optparse-applicative-0.18.1.0_1 \
		os-string-2.0.7 \
		pem-0.2.4 \
		prettyclass-1.0.0.0 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.1.0 \
		random-1.3.1 \
		raw-strings-qq-1.1 \
		readable-0.3.1_2 \
		regex-base-0.94.0.3 \
		regex-posix-0.96.0.2 \
		scientific-0.3.8.0_2 \
		serialise-0.2.6.1_4 \
		snap-core-1.0.5.1_6 \
		snap-server-1.1.2.1_5 \
		socks-0.6.1 \
		splitmix-0.1.1 \
		streaming-commons-0.2.3.0 \
		strict-0.5.1_1 \
		tagged-0.8.9 \
		tasty-1.5.3_1 \
		th-compat-0.1.6 \
		these-1.2.1_2 \
		tls-2.1.10 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		unix-compat-0.7.4 \
		unix-time-0.4.16 \
		unordered-containers-0.2.20_4 \
		utf8-string-1.0.2 \
		vector-0.13.2.0_1 \
		vector-stream-0.1.0.1_3 \
		zip-archive-0.4.3.2_1 \
		zlib-0.7.1.0_2 \
		zlib-bindings-0.1.1.5_2

MAKE_ENV=	ELM_HOME=${WRKDIR}/elm-compiler-bootstrap-${PORTVERSION}

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
