# $FreeBSD$

PORTNAME=	hedgewars
PORTVERSION=	1.0.0
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

USE_CABAL=	ConfigFile-1.1.4 \
		MissingH-1.4.3.0 \
		SHA-1.6.4.4 \
		aeson-1.4.7.1_1 \
		attoparsec-0.13.2.4 \
		base-compat-0.11.1 \
		base-compat-batteries-0.11.1 \
		base-orphans-0.8.2 \
		conduit-1.3.2 \
		dlist-0.8.0.8 \
		entropy-0.4.1.5 \
		exceptions-0.10.4_1 \
		hashable-1.3.0.0_1 \
		hslogger-1.3.1.0_1 \
		integer-logarithms-1.0.3_2 \
		libyaml-0.1.2 \
		mono-traversable-1.0.15.1 \
		network-2.8.0.1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 \
		primitive-0.7.0.1 \
		random-1.1_1 \
		regex-base-0.94.0.0_1 \
		regex-compat-0.95.2.0_1 \
		regex-posix-0.96.0.0_1 \
		regex-tdfa-1.3.1.0_1 \
		resourcet-1.2.3 \
		sandi-0.5_1 \
		scientific-0.3.6.2 \
		split-0.2.3.4 \
		tagged-0.8.6_2 \
		th-abstraction-0.3.2.0 \
		time-compat-1.9.3 \
		unliftio-core-0.2.0.1_1 \
		unordered-containers-0.2.10.0_1 \
		utf8-string-1.0.1.1_3 \
		uuid-types-1.0.3_2 \
		vector-0.12.1.2 \
		vector-algorithms-0.8.0.3 \
		yaml-0.11.3.0 \
		zlib-0.6.2.1_1

EXECUTABLES=	hedgewars-server checker

.include <bsd.port.mk>
