# $FreeBSD$

PORTNAME=	ShellCheck
DISTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shell script analysis tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cabal

USE_CABAL=	Diff-0.4.0 \
		QuickCheck-2.14 \
		aeson-1.5.1.0 \
		assoc-1.0.1_1 \
		attoparsec-0.13.2.4 \
		base-compat-0.11.1 \
		base-compat-batteries-0.11.1 \
		base-orphans-0.8.2 \
		bifunctors-5.5.7 \
		cabal-doctest-1.0.8_1 \
		comonad-5.0.6 \
		distributive-0.6.2 \
		dlist-0.8.0.8 \
		hashable-1.3.0.0_1 \
		integer-logarithms-1.0.3_2 \
		primitive-0.7.0.1 \
		random-1.1_1 \
		regex-base-0.94.0.0_1 \
		regex-tdfa-1.3.1.0_1 \
		scientific-0.3.6.2 \
		splitmix-0.0.4 \
		tagged-0.8.6_2 \
		th-abstraction-0.3.2.0 \
		these-1.1 \
		time-compat-1.9.3 \
		transformers-compat-0.6.5 \
		unordered-containers-0.2.10.0_1 \
		uuid-types-1.0.3_2 \
		vector-0.12.1.2

EXECUTABLES=	shellcheck

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc
MANPAGES_PLIST_FILES=	share/man/man1/shellcheck.1.gz

post-build-MANPAGES-on:
	cd ${WRKSRC} && ./manpage

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/shellcheck.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
