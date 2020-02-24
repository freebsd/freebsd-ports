# $FreeBSD$

PORTNAME=	ShellCheck
DISTVERSION=	0.7.0
CATEGORIES=	devel haskell

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Shell script analysis tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cabal

USE_CABAL=	aeson-1.4.6.0 \
		attoparsec-0.13.2.3 \
		base-compat-0.11.1 \
		base-orphans-0.8.2 \
		Diff-0.4.0 \
		dlist-0.8.0.7 \
		hashable-1.3.0.0 \
		integer-logarithms-1.0.3 \
		primitive-0.7.0.0 \
		QuickCheck-2.13.2 \
		random-1.1 \
		regex-base-0.94.0.0 \
		regex-tdfa-1.3.1.0 \
		scientific-0.3.6.2 \
		splitmix-0.0.3 \
		tagged-0.8.6 \
		th-abstraction-0.3.2.0 \
		time-compat-1.9.2.2 \
		unordered-containers-0.2.10.0_1 \
		uuid-types-1.0.3_2 \
		vector-0.12.1.2

EXECUTABLES=	shellcheck
PLIST_FILES=	share/man/man1/shellcheck.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/shellcheck.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
