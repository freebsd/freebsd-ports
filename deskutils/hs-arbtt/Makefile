PORTNAME=		arbtt
PORTVERSION=		0.12.0.3
PORTREVISION=		1
CATEGORIES=		deskutils haskell

MAINTAINER=		mail@dbalan.in
COMMENT=		Completely automatic time tracker for X11 desktop
WWW=		https://arbtt.nomeata.de/

LICENSE=		GPLv2
LICENSE_FILE=		${WRKSRC}/LICENSE

LIB_DEPENDS=		libpcre.so:devel/pcre

USES=			xorg cabal
USE_XORG=		x11 xscrnsaver xext xrandr xinerama
USE_CABAL=		OneTuple-0.4.2_1 \
			QuickCheck-2.16.0.0 \
			StateVar-1.2.2 \
			X11-1.10.3_1 \
			aeson-2.2.3.0_4 \
			ansi-terminal-1.1.5 \
			ansi-terminal-types-1.1.3 \
			assoc-1.1.1_1 \
			attoparsec-0.14.4_6 \
			attoparsec-aeson-2.2.2.0 \
			base-orphans-0.9.3 \
			bifunctors-5.6.2_2 \
			bitvec-1.1.5.0_3 \
			bytestring-progress-1.4 \
			character-ps-0.1 \
			colour-2.3.6 \
			comonad-5.0.9_1 \
			conduit-1.3.6.1 \
			contravariant-1.5.5 \
			data-default-0.8.0.1 \
			data-default-class-0.2.0.0 \
			data-fix-0.3.4_1 \
			distributive-0.6.2.1_1 \
			dlist-1.0_2 \
			generically-0.1.1_4 \
			hashable-1.5.0.0_1 \
			hsc2hs-0.68.10_4 \
			indexed-traversable-0.1.4_1 \
			indexed-traversable-instances-0.1.2_1 \
			integer-conversion-0.1.1_1 \
			integer-logarithms-1.0.4 \
			mono-traversable-1.0.21.0 \
			network-uri-2.6.4.2_1 \
			optparse-applicative-0.19.0.0 \
			pcre-light-0.4.1.3_1 \
			prettyprinter-1.7.1 \
			prettyprinter-ansi-terminal-1.1.3 \
			primitive-0.9.1.0 \
			random-1.3.1 \
			resourcet-1.3.0 \
			scientific-0.3.8.0_2 \
			semialign-1.3.1_2 \
			semigroupoids-6.0.1_2 \
			split-0.2.5 \
			splitmix-0.1.3.1 \
			strict-0.5.1_1 \
			tagged-0.8.10 \
			tasty-1.5.3_2 \
			terminal-progress-bar-0.4.2 \
			terminal-size-0.3.4_1 \
			text-iso8601-0.1.1_2 \
			text-short-0.1.6_3 \
			th-abstraction-0.7.1.0_1 \
			th-compat-0.1.6 \
			these-1.2.1_2 \
			time-compat-1.9.8 \
			transformers-compat-0.7.2 \
			tz-0.1.3.6_9 \
			tzdata-0.2.20250115.0 \
			unliftio-core-0.2.1.0_4 \
			unordered-containers-0.2.21_1 \
			utf8-string-1.0.2 \
			uuid-types-1.0.6_3 \
			vector-0.13.2.0_2 \
			vector-algorithms-0.9.1.0 \
			vector-stream-0.1.0.1_4 \
			witherable-0.5_1

CABAL_REVISION=		1
CABAL_EXECUTABLES=	arbtt-capture arbtt-stats arbtt-recover arbtt-import arbtt-dump

SUB_FILES=		pkg-message
SUB_LIST=		EXAMPLESDIR=${EXAMPLESDIR}

OPTIONS_DEFINE=		MANPAGES
OPTIONS_SUB=		yes

OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/profile-docbook.xsl:textproc/docbook-xsl \
				xsltproc:textproc/libxslt

post-patch-MANPAGES-on:
	@${REINPLACE_CMD} -e "s|/usr/share/xml/docbook/stylesheet/nwalsh/manpages/profile-docbook.xsl|${LOCALBASE}/share/xsl/docbook/manpages/profile-docbook.xsl|g" \
		${WRKSRC}/doc/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/categorize.cfg ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/arbtt-capture.desktop ${STAGEDIR}${EXAMPLESDIR}

post-install-MANPAGES-on:
	cd ${WRKSRC}/doc && ${MAKE} man
.for l in arbtt-stats arbtt-recover arbtt-import arbtt-dump arbtt-capture
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/${l}.1 ${STAGEDIR}${PREFIX}/share/man/man1/
.endfor

.include <bsd.port.mk>
