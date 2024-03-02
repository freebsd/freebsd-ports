PORTNAME=	ShellCheck
DISTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Shell script analysis tool
WWW=		https://www.shellcheck.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cabal

USE_CABAL=	Diff-0.4.1 \
		OneTuple-0.4.1.1_1 \
		QuickCheck-2.14.3 \
		StateVar-1.2.2 \
		aeson-2.2.1.0_1 \
		assoc-1.1_1 \
		base-orphans-0.9.1 \
		bifunctors-5.6.1_2 \
		comonad-5.0.8_2 \
		contravariant-1.5.5 \
		data-fix-0.3.2_5 \
		distributive-0.6.2.1_1 \
		dlist-1.0_1 \
		fgl-5.8.2.0 \
		generically-0.1.1_2 \
		hashable-1.4.3.0_1 \
		indexed-traversable-0.1.3 \
		indexed-traversable-instances-0.1.1.2_2 \
		integer-conversion-0.1.0.1_1 \
		integer-logarithms-1.0.3.1_5 \
		network-uri-2.6.4.2_1 \
		primitive-0.9.0.0 \
		random-1.2.1.2 \
		regex-base-0.94.0.2_4 \
		regex-tdfa-1.3.2.2_2 \
		scientific-0.3.7.0_7 \
		semialign-1.3_1 \
		semigroupoids-6.0.0.1_1 \
		splitmix-0.1.0.5 \
		strict-0.5_1 \
		tagged-0.8.8 \
		text-iso8601-0.1_1 \
		text-short-0.1.5_3 \
		th-abstraction-0.6.0.0_1 \
		th-compat-0.1.4_4 \
		these-1.2_1 \
		time-compat-1.9.6.1_6 \
		transformers-compat-0.7.2 \
		unordered-containers-0.2.20_1 \
		uuid-types-1.0.5.1 \
		vector-0.13.1.0 \
		vector-stream-0.1.0.1 \
		witherable-0.4.2_4

CABAL_REVISION=	2
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
