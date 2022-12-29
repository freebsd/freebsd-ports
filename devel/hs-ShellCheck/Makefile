PORTNAME=	ShellCheck
DISTVERSION=	0.9.0
CATEGORIES=	devel haskell

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Shell script analysis tool
WWW=		https://www.shellcheck.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cabal

USE_CABAL=	Diff-0.4.1 \
		OneTuple-0.3.1_3 \
		QuickCheck-2.14.2 \
		StateVar-1.2.2 \
		aeson-2.1.1.0 \
		assoc-1.0.2_3 \
		attoparsec-0.14.4_2 \
		base-compat-0.12.2 \
		base-compat-batteries-0.12.2 \
		base-orphans-0.8.7 \
		bifunctors-5.5.14 \
		comonad-5.0.8_1 \
		contravariant-1.5.5 \
		data-fix-0.3.2_3 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		fgl-5.8.0.0 \
		generically-0.1 \
		hashable-1.4.1.0 \
		indexed-traversable-0.1.2_2 \
		indexed-traversable-instances-0.1.1.1 \
		integer-logarithms-1.0.3.1_3 \
		primitive-0.7.4.0 \
		random-1.2.1.1 \
		regex-base-0.94.0.2_1 \
		regex-tdfa-1.3.2 \
		scientific-0.3.7.0_3 \
		semialign-1.2.0.1_3 \
		semigroupoids-5.3.7 \
		splitmix-0.1.0.4_1 \
		strict-0.4.0.1_4 \
		tagged-0.8.6.1_3 \
		text-short-0.1.5_1 \
		th-abstraction-0.4.5.0 \
		these-1.1.1.1_6 \
		time-compat-1.9.6.1_4 \
		transformers-compat-0.7.2 \
		unordered-containers-0.2.19.1_1 \
		uuid-types-1.0.5_3 \
		vector-0.13.0.0_1 \
		vector-stream-0.1.0.0_1 \
		witherable-0.4.2_3

CABAL_EXECUTABLES=	shellcheck

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
