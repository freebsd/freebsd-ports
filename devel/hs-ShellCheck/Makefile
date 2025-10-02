PORTNAME=	ShellCheck
DISTVERSION=	0.11.0
CATEGORIES=	devel haskell

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Shell script analysis tool
WWW=		https://www.shellcheck.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cabal

USE_CABAL=	Diff-1.0.2 \
		OneTuple-0.4.2_1 \
		QuickCheck-2.16.0.0 \
		StateVar-1.2.2 \
		aeson-2.2.3.0_4 \
		ansi-terminal-1.1.3 \
		ansi-terminal-types-1.1.3 \
		assoc-1.1.1_1 \
		base-orphans-0.9.3 \
		bifunctors-5.6.2_2 \
		character-ps-0.1 \
		colour-2.3.6 \
		comonad-5.0.9_1 \
		contravariant-1.5.5 \
		data-fix-0.3.4_1 \
		distributive-0.6.2.1_1 \
		dlist-1.0_2 \
		fgl-5.8.3.0_1 \
		generically-0.1.1_4 \
		hashable-1.5.0.0_1 \
		indexed-traversable-0.1.4_1 \
		indexed-traversable-instances-0.1.2_1 \
		integer-conversion-0.1.1_1 \
		integer-logarithms-1.0.4 \
		network-uri-2.6.4.2_1 \
		optparse-applicative-0.19.0.0 \
		os-string-2.0.8 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.1.0 \
		random-1.3.1 \
		regex-base-0.94.0.3 \
		regex-tdfa-1.3.2.5 \
		scientific-0.3.8.0_2 \
		semialign-1.3.1_2 \
		semigroupoids-6.0.1_2 \
		splitmix-0.1.3.1 \
		strict-0.5.1_1 \
		tagged-0.8.9 \
		tasty-1.5.3_2 \
		text-iso8601-0.1.1_2 \
		text-short-0.1.6_3 \
		th-abstraction-0.7.1.0_1 \
		th-compat-0.1.6 \
		these-1.2.1_2 \
		time-compat-1.9.8 \
		transformers-compat-0.7.2 \
		unordered-containers-0.2.20.1 \
		uuid-types-1.0.6_3 \
		vector-0.13.2.0_2 \
		vector-stream-0.1.0.1_4 \
		witherable-0.5_1

CABAL_EXECUTABLES=	shellcheck

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc
MANPAGES_PLIST_FILES=	share/man/man1/shellcheck.1.gz

post-build-MANPAGES-on:
	cd ${WRKSRC} && ${SH} manpage

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/shellcheck.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
