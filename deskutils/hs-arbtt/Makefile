PORTNAME=		arbtt
PORTVERSION=		0.11.1
CATEGORIES=		deskutils haskell

MAINTAINER=		mail@dbalan.in
COMMENT=		Completely automatic time tracker for X11 desktop

LICENSE=		GPLv2
LICENSE_FILE=		${WRKSRC}/LICENSE

LIB_DEPENDS=		libpcre.so:devel/pcre

USES=			xorg cabal
USE_XORG=		x11 xscrnsaver xext xrandr xinerama
USE_CABAL=		OneTuple-0.3.1_2 \
			QuickCheck-2.14.2 \
			StateVar-1.2.2 \
			X11-1.10.2 \
			aeson-2.0.3.0 \
			assoc-1.0.2_2 \
			attoparsec-0.14.4_1 \
			base-compat-0.12.1 \
			base-compat-batteries-0.12.1_2 \
			base-orphans-0.8.6 \
			bifunctors-5.5.12 \
			bytestring-progress-1.4 \
			comonad-5.0.8_1 \
			conduit-1.3.4.2 \
			contravariant-1.5.5 \
			data-default-class-0.1.2.0 \
			data-fix-0.3.2_2 \
			distributive-0.6.2.1_1 \
			dlist-1.0 \
			hashable-1.4.0.2 \
			hsc2hs-0.68.8 \
			indexed-traversable-0.1.2_1 \
			indexed-traversable-instances-0.1.1 \
			integer-logarithms-1.0.3.1_2 \
			mono-traversable-1.0.15.3 \
			pcre-light-0.4.1.0 \
			primitive-0.7.3.0 \
			random-1.2.1.1 \
			resourcet-1.2.4.3_1 \
			scientific-0.3.7.0_2 \
			semialign-1.2.0.1_1 \
			semigroupoids-5.3.7 \
			split-0.2.3.4_2 \
			splitmix-0.1.0.4 \
			strict-0.4.0.1_4 \
			tagged-0.8.6.1_2 \
			terminal-progress-bar-0.4.1 \
			terminal-size-0.3.3 \
			text-short-0.1.5 \
			th-abstraction-0.4.3.0 \
			these-1.1.1.1_5 \
			time-compat-1.9.6.1_3 \
			transformers-compat-0.7.1_1 \
			unliftio-core-0.2.0.1_2 \
			unordered-containers-0.2.19.1 \
			utf8-string-1.0.2 \
			uuid-types-1.0.5_2 \
			vector-0.12.3.1_1 \
			vector-algorithms-0.8.0.4_1 \
			witherable-0.4.2_2

EXECUTABLES=		arbtt-capture arbtt-stats arbtt-recover arbtt-import arbtt-dump

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
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/${l}.1 ${STAGEDIR}${PREFIX}/man/man1/
.endfor

.include <bsd.port.mk>
