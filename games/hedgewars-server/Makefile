# $FreeBSD$

PORTNAME=	hedgewars
PORTVERSION=	0.9.25
CATEGORIES=	games
MASTER_SITES=	http://www.hedgewars.org/download/releases/ \
		http://mirror.amdmi3.ru/distfiles/
PKGNAMESUFFIX=	-server
DISTNAME=	${PORTNAME}-src-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} # cabal.mk has different default from bsd.port.mk
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Server part of free Worms-like turn based strategy game

LICENSE=	GPLv2

USES=		cabal tar:bzip2

WRKSRC_SUBDIR=	gameServer

USE_CABAL=	ConfigFile-1.1.4 HUnit-1.6.0.0 MissingH-1.4.1.0 SHA-1.6.4.4 \
		aeson-1.4.3.0 attoparsec-0.13.2.2_2 base-compat-0.10.5 \
		call-stack-0.1.0 conduit-1.3.1.1 dlist-0.8.0.6 entropy-0.4.1.4 \
		exceptions-0.10.2 hashable-1.2.7.0_1 hslogger-1.3.0.0 \
		integer-logarithms-1.0.3 libyaml-0.1.1.0 \
		mono-traversable-1.0.11.0 network-2.7.0.2 \
		old-locale-1.0.0.7_2 old-time-1.1.0.3_2 primitive-0.6.4.0_1 \
		random-1.1 regex-base-0.93.2 regex-compat-0.95.1 \
		regex-posix-0.95.2 regex-tdfa-1.2.3.1 resourcet-1.2.2 sandi-0.5 \
		scientific-0.3.6.2 split-0.2.3.3_1 tagged-0.8.6 \
		th-abstraction-0.3.1.0 time-locale-compat-0.1.1.5 \
		transformers-compat-0.6.4 unliftio-core-0.1.2.0_1 \
		unordered-containers-0.2.10.0 utf8-string-1.0.1.1_3 \
		uuid-types-1.0.3_1 vector-0.12.0.3 vector-algorithms-0.8.0.1 \
		yaml-0.11.0.0 zlib-0.6.2

EXECUTABLES=	hedgewars-server checker

.include <bsd.port.mk>
