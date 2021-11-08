PORTNAME=	ShellCheck
DISTVERSION=	0.8.0
CATEGORIES=	devel haskell

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Shell script analysis tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cabal

USE_CABAL=	Diff-0.4.0 \
		OneTuple-0.3.1 \
		QuickCheck-2.14.2 \
		StateVar-1.2.2 \
		aeson-2.0.1.0 \
		assoc-1.0.2_2 \
		attoparsec-0.14.2 \
		base-compat-0.12.1 \
		base-compat-batteries-0.12.1 \
		base-orphans-0.8.6 \
		bifunctors-5.5.11_1 \
		comonad-5.0.8_1 \
		contravariant-1.5.5 \
		data-fix-0.3.2_2 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		hashable-1.3.5.0 \
		indexed-traversable-0.1.2 \
		indexed-traversable-instances-0.1.1 \
		integer-logarithms-1.0.3.1_2 \
		primitive-0.7.3.0 \
		random-1.2.1 \
		regex-base-0.94.0.1_1 \
		regex-tdfa-1.3.1.1_1 \
		scientific-0.3.7.0_1 \
		semialign-1.2.0.1 \
		semigroupoids-5.3.6_1 \
		splitmix-0.1.0.4 \
		strict-0.4.0.1_2 \
		tagged-0.8.6.1_2 \
		th-abstraction-0.4.3.0 \
		these-1.1.1.1_4 \
		time-compat-1.9.6.1_2 \
		transformers-compat-0.7.1 \
		unordered-containers-0.2.14.0 \
		uuid-types-1.0.5_1 \
		vector-0.12.3.1 \
		witherable-0.4.2_1

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
