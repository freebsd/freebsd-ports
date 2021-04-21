PORTNAME=	ShellCheck
DISTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Shell script analysis tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cabal

USE_CABAL=	Diff-0.4.0 \
		QuickCheck-2.14.2 \
		aeson-1.5.6.0_1 \
		assoc-1.0.2_1 \
		attoparsec-0.14.1 \
		base-compat-0.11.2 \
		base-compat-batteries-0.11.2 \
		base-orphans-0.8.4 \
		bifunctors-5.5.10 \
		comonad-5.0.8 \
		data-fix-0.3.1 \
		distributive-0.6.2.1 \
		dlist-1.0 \
		hashable-1.3.1.0 \
		indexed-traversable-0.1.1 \
		integer-logarithms-1.0.3.1 \
		primitive-0.7.1.0_2 \
		random-1.2.0_5 \
		regex-base-0.94.0.1 \
		regex-tdfa-1.3.1.0_2 \
		scientific-0.3.6.2 \
		splitmix-0.1.0.3 \
		strict-0.4.0.1 \
		tagged-0.8.6.1_1 \
		th-abstraction-0.4.2.0 \
		these-1.1.1.1_1 \
		time-compat-1.9.5_1 \
		transformers-compat-0.6.6 \
		unordered-containers-0.2.13.0 \
		uuid-types-1.0.4 \
		vector-0.12.3.0

EXECUTABLES=	shellcheck

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES
# hs-pandoc is broken on 11.4 i386 due to missing __atomic_load_8;
# make sure we still have a package (just without a manual) there
# anyway.
OPTIONS_EXCLUDE=	${${ARCH} == i386 && ${OPSYS} == FreeBSD && ${OSVERSION} < 1201525:?MANPAGES:}

MANPAGES_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc
MANPAGES_PLIST_FILES=	share/man/man1/shellcheck.1.gz

post-build-MANPAGES-on:
	cd ${WRKSRC} && ./manpage

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/shellcheck.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
