# $FreeBSD$

PORTNAME=	ShellCheck
DISTVERSION=	0.6.0
PORTREVISION=	3
CATEGORIES=	devel haskell

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Shell script analysis tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cabal

USE_CABAL=	QuickCheck-2.12.6.1_1 aeson-1.4.2.0_1 attoparsec-0.13.2.2 \
		base-compat-0.10.5 dlist-0.8.0.5 erf-2.0.0.0 hashable-1.2.7.0_1 \
		integer-logarithms-1.0.2.2 primitive-0.6.4.0_1 random-1.1_1 \
		regex-base-0.93.2 regex-tdfa-1.2.3.1 scientific-0.3.6.2 \
		tagged-0.8.6 tf-random-0.5 th-abstraction-0.2.10.0 \
		time-locale-compat-0.1.1.5 unordered-containers-0.2.10.0 \
		uuid-types-1.0.3_1 vector-0.12.0.2

EXECUTABLES=	shellcheck

.include <bsd.port.mk>
