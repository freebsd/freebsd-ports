# $FreeBSD$

PORTNAME=	elm
PORTVERSION=	0.19.0
CATEGORIES=	lang
MASTER_SITES=	LOCAL/arrowd/:package_list
DISTFILES=	all-packages-${PORTNAME}-${PORTVERSION}:package_list
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Delightful language for reliable webapps

LICENSE=	BSD3CLAUSE

USES=		cabal

USE_GITHUB=	yes
GH_ACCOUNT=	elm
GH_PROJECT=	compiler

USE_CABAL=	HTTP-4000.3.12_2 \
		HUnit-1.6.0.0 \
		SHA-1.6.4.4 \
		ansi-terminal-0.8.2 \
		ansi-wl-pprint-0.6.8.2_2 \
		asn1-encoding-0.9.5 \
		asn1-parse-0.9.4 \
		asn1-types-0.3.3 \
		async-2.2.1_1 \
		attoparsec-0.13.2.2_3 \
		base-orphans-0.8.1 \
		basement-0.0.10_2 \
		binary-0.8.7.0 \
		blaze-builder-0.4.1.0 \
		bytestring-builder-0.10.8.2.0 \
		call-stack-0.1.0 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.1 \
		clock-0.8 \
		colour-2.3.5 \
		connection-0.3.0_1 \
		containers-0.5.11.0_3 \
		cookie-0.4.4 \
		cryptonite-0.26 \
		data-default-class-0.1.2.0 \
		digest-0.0.1.2 \
		edit-distance-0.2.2.1_1 \
		exceptions-0.10.2 \
		file-embed-0.0.11 \
		hashable-1.2.7.0_1 \
		haskeline-0.7.5.0 \
		hourglass-0.2.12 \
		http-client-0.5.14_1 \
		http-client-tls-0.3.5.3_1 \
		http-types-0.12.3 \
		integer-logarithms-1.0.3 \
		io-streams-1.5.1.0 \
		io-streams-haproxy-1.0.1.0 \
		language-glsl-0.3.0_1 \
		lifted-base-0.2.3.12 \
		logict-0.7.0.1 \
		memory-0.14.18_1 \
		mime-types-0.1.0.9 \
		monad-control-1.0.2.3 \
		network-2.6.3.6 \
		network-uri-2.6.1.0_1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 \
		parsec-3.1.13.0_2 \
		pem-0.2.4 \
		prettyclass-1.0.0.0 \
		primitive-0.6.4.0_1 \
		random-1.1_1 \
		raw-strings-qq-1.1 \
		readable-0.3.1 \
		regex-base-0.93.2_1 \
		regex-posix-0.95.2 \
		scientific-0.3.6.2 \
		snap-core-1.0.4.0 \
		snap-server-1.1.1.1_1 \
		socks-0.6.0 \
		streaming-commons-0.2.1.1 \
		text-1.2.3.1_2 \
		tls-1.5.0 \
		transformers-base-0.4.5.2 \
		transformers-compat-0.6.5 \
		unix-compat-0.5.1_1 \
		unordered-containers-0.2.10.0_1 \
		utf8-string-1.0.1.1_3 \
		vector-0.12.0.3_2 \
		x509-1.7.5_1 \
		x509-store-1.6.7_1 \
		x509-system-1.6.6 \
		x509-validation-1.6.11 \
		zip-archive-0.3.2.1_1 \
		zlib-0.6.2 \
		zlib-bindings-0.1.1.5_2

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/all-packages?${PORTNAME}-${PORTVERSION} ${WRKSRC}/elm_all-packages

.include <bsd.port.mk>
