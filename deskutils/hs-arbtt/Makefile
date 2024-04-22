PORTNAME=		arbtt
PORTVERSION=		0.12.0.3
CATEGORIES=		deskutils haskell

MAINTAINER=		mail@dbalan.in
COMMENT=		Completely automatic time tracker for X11 desktop
WWW=		https://arbtt.nomeata.de/

LICENSE=		GPLv2
LICENSE_FILE=		${WRKSRC}/LICENSE

LIB_DEPENDS=		libpcre.so:devel/pcre

USES=			xorg cabal
USE_XORG=		x11 xscrnsaver xext xrandr xinerama
USE_CABAL=		OneTuple-0.4.1.1_1 \
			QuickCheck-2.14.3 \
			StateVar-1.2.2 \
			X11-1.10.3 \
			aeson-2.2.1.0_1 \
			assoc-1.1_1 \
			attoparsec-0.14.4_5 \
			attoparsec-aeson-2.2.0.1 \
			base-orphans-0.9.1 \
			bifunctors-5.6.1_2 \
			bitvec-1.1.5.0 \
			bytestring-progress-1.4 \
			comonad-5.0.8_2 \
			conduit-1.3.5 \
			contravariant-1.5.5 \
			data-default-0.7.1.1 \
			data-default-class-0.1.2.0 \
			data-default-instances-containers-0.0.1 \
			data-default-instances-dlist-0.0.1 \
			data-default-instances-old-locale-0.0.1 \
			data-fix-0.3.2_5 \
			distributive-0.6.2.1_1 \
			dlist-1.0_1 \
			generically-0.1.1_2 \
			hashable-1.4.3.0_1 \
			hsc2hs-0.68.10_1 \
			indexed-traversable-0.1.3 \
			indexed-traversable-instances-0.1.1.2_2 \
			integer-conversion-0.1.0.1_1 \
			integer-logarithms-1.0.3.1_5 \
			mono-traversable-1.0.15.3 \
			network-uri-2.6.4.2_1 \
			old-locale-1.0.0.7_2 \
			pcre-light-0.4.1.2 \
			primitive-0.9.0.0 \
			random-1.2.1.2 \
			resourcet-1.3.0 \
			scientific-0.3.7.0_7 \
			semialign-1.3_1 \
			semigroupoids-6.0.0.1_1 \
			split-0.2.5 \
			splitmix-0.1.0.5 \
			strict-0.5_1 \
			tagged-0.8.8 \
			terminal-progress-bar-0.4.2 \
			terminal-size-0.3.4 \
			text-iso8601-0.1_1 \
			text-short-0.1.5_3 \
			th-abstraction-0.6.0.0_1 \
			th-compat-0.1.4_4 \
			these-1.2_1 \
			time-compat-1.9.6.1_6 \
			transformers-compat-0.7.2 \
			tz-0.1.3.6_5 \
			tzdata-0.2.20240201.0 \
			unliftio-core-0.2.1.0_3 \
			unordered-containers-0.2.20_1 \
			utf8-string-1.0.2 \
			uuid-types-1.0.5.1 \
			vector-0.13.1.0 \
			vector-algorithms-0.9.0.1_3 \
			vector-stream-0.1.0.1 \
			witherable-0.4.2_4

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
