# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

# To update this port first go to
# https://github.com/arrowd/stack-dependencies, change the
# version in the Makefile there, regenerate the stack-dependencies
# tarball, commit Makefile changes, create a new tag (release)
# matching the new stack version, and upload the tarball.  Finally
# bump the version here.

PORTNAME=	stack
PORTVERSION=	1.9.3
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Cross-platform program for developing Haskell programs

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	happy:devel/hs-happy
RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss

USES=		cabal

USE_CABAL=	Glob-0.10.0 HUnit-1.6.0.0 QuickCheck-2.12.6.1_1 StateVar-1.1.1.1 \
		aeson-1.4.2.0_1 aeson-compat-0.3.9 annotated-wl-pprint-0.7.0 \
		ansi-terminal-0.9 ansi-wl-pprint-0.6.8.2_1 asn1-encoding-0.9.5 \
		asn1-parse-0.9.4 asn1-types-0.3.2 async-2.2.1_1 attoparsec-0.13.2.2 \
		attoparsec-iso8601-1.0.1.0 auto-update-0.1.4.1 base16-bytestring-0.1.1.6 \
		base64-bytestring-1.0.0.2 base-compat-0.10.5 base-orphans-0.8 \
		base-prelude-1.3 basement-0.0.10_1 bifunctors-5.5.3 \
		bindings-uname-0.1 bitarray-0.0.1.1 blaze-builder-0.4.1.0 \
		blaze-html-0.9.1.1 blaze-markup-0.8.2.2 byteable-0.1.1 \
		cabal-doctest-1.0.6_2 call-stack-0.1.0 case-insensitive-1.2.0.11 \
		cereal-0.5.8.0 clock-0.7.2 cmdargs-0.10.20 colour-2.3.4 \
		comonad-5.0.4 conduit-1.3.1.1 conduit-extra-1.3.1.1 \
		connection-0.2.8 contravariant-1.5 cookie-0.4.4 cryptohash-0.11.9 \
		cryptohash-sha256-0.11.101.0_2 cryptonite-0.25 cryptonite-conduit-0.2.2 \
		data-default-class-0.1.2.0 digest-0.0.1.2 distributive-0.6 \
		dlist-0.8.0.5 easy-file-0.2.2 ed25519-0.0.5.0_2 echo-0.1.3_1 \
		either-5.0.1 erf-2.0.0.0 exceptions-0.10.0_2 extra-1.6.14 \
		fast-logger-2.4.13 file-embed-0.0.11 filelock-0.1.1.2 free-5.1 \
		fsnotify-0.3.0.1_1 generic-deriving-1.12.3 githash-0.1.3.1 \
		hackage-security-0.5.3.0_4 hashable-1.2.7.0_1 hourglass-0.2.12 \
		hpack-0.31.2 hsc2hs-0.68.4 hspec-2.7.0 hspec-core-2.7.0 \
		hspec-discover-2.7.0 hspec-expectations-0.8.2 \
		hspec-smallcheck-0.5.2 http-api-data-0.4 http-client-0.6.2 \
		http-client-tls-0.3.5.3 http-conduit-2.3.6.1 http-types-0.12.3 \
		infer-license-0.2.0 integer-logarithms-1.0.2.2 libyaml-0.1.1.0 \
		lifted-base-0.2.3.12 logict-0.6.0.2 megaparsec-7.0.4 \
		memory-0.14.18_1 microlens-0.4.10 microlens-th-0.4.2.3 \
		mime-types-0.1.0.9 mintty-0.1.2 monad-control-1.0.2.3 \
		monad-logger-0.3.30 monad-loops-0.4.3 mono-traversable-1.0.11.0 \
		mustache-2.3.0 neat-interpolation-0.3.2.4 network-2.7.0.2_2 \
		network-uri-2.6.1.0_1 open-browser-0.2.1.0 old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 optparse-applicative-0.14.3.0 \
		optparse-simple-0.1.1.1 parser-combinators-1.0.1 path-0.6.1_1 \
		path-io-1.4.2 path-pieces-0.2.1_1 pem-0.2.4 persistent-2.9.1_1 \
		persistent-sqlite-2.9.2 persistent-template-2.6.0 \
		primitive-0.6.4.0_1 profunctors-5.3 project-template-0.2.0.1 \
		quickcheck-io-0.2.0 random-1.1_1 regex-applicative-0.3.3 \
		regex-applicative-text-0.1.0.1_3 resource-pool-0.2.3.2 \
		resourcet-1.2.2 retry-0.8.0.0 rio-0.1.8.0 safe-0.3.17 \
		scientific-0.3.6.2 semigroupoids-5.3.2 semigroups-0.18.5 \
		setenv-0.1.1.3_1 silently-1.2.5 smallcheck-1.1.5 socks-0.5.6_1 \
		split-0.2.3.3_1 stm-chans-3.0.0.4_1 store-0.5.0.1 store-core-0.4.4 \
		streaming-commons-0.2.1.0 syb-0.7 tar-0.5.1.0_1 tagged-0.8.6 temporary-1.3 \
		text-metrics-0.3.0_4 tf-random-0.5 th-abstraction-0.2.11.0 \
		th-expand-syns-0.4.4.0_1 th-lift-0.7.11 th-lift-instances-0.1.11 \
		th-orphans-0.13.6 th-reify-many-0.1.8 th-utilities-0.2.1.0 \
		time-locale-compat-0.1.1.5 tls-1.4.1 transformers-base-0.4.5.2 \
		transformers-compat-0.6.2 typed-process-0.2.4.0 \
		unicode-transforms-0.3.5 unix-compat-0.5.1 unix-time-0.4.5 \
		unliftio-0.2.10 unliftio-core-0.1.2.0_1 \
		unordered-containers-0.2.10.0 uuid-types-1.0.3_1 vector-0.12.0.2 \
		vector-algorithms-0.8.0.1 void-0.7.2 x509-1.7.5 \
		x509-store-1.6.7 x509-system-1.6.6 x509-validation-1.6.11 \
		yaml-0.11.0.0 zip-archive-0.4 zlib-0.6.2

#PLIST_FILES=	etc/bash_completion.d/_stack.bash \
#		share/zsh/site-functions/_stack

.include <bsd.port.mk>
