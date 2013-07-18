# Created by: Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lynx
DISTVERSION=	${VERSION}.${MINOR_VERSION:S/.//}
CATEGORIES=	japanese www ipv6
MASTER_SITES=	http://lynx.isc.org/current/ \
		http://ftp2.uk.freebsd.org/sites/lynx.isc.org/current/
DISTNAME=	${PORTNAME}${VERSION}${MINOR_VERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console WWW client (browser) with multi-byte encoding support

LICENSE=	GPLv2

VERSION=	2.8.7
MINOR_VERSION=	rel.1

CONFLICTS=	lynx-2.* ja-lynx-2.8.8.*

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-screen=ncurses --with-zlib --libdir="${L_LIB}" \
		--enable-nsl-fork --enable-ipv6 \
		--enable-cjk --enable-internal-links \
		--with-bzlib
MAKE_ARGS=	helpdir=${L_HELP} docdir=${DOCSDIR}
MAKEFILE=	makefile

WRKSRC=		${WRKDIR}/${PORTNAME}${VERSION:S/./-/g}
L_LIB=		${PREFIX}/etc
L_HELP=		${PREFIX}/share/lynx_help

MAN1=		lynx.1

OPTIONS_DEFINE=	JAPANESE_UTF8 COLOR_STYLE DEFAULT_COLORS DOCS
OPTIONS_SUB=	yes

JAPANESE_UTF8_DESC=	Enable experimental Japanese UTF-8 logic
COLOR_STYLE_DESC=	Enable color style (ncurses/curses)
DEFAULT_COLORS_DESC=	Enable default colors (ncurses/slang)

JAPANESE_UTF8_USES=		iconv
JAPANESE_UTF8_CONFIGURE_ON=	--with-libiconv-prefix=${LOCALBASE}
JAPANESE_UTF8_CONFIGURE_ENABLE=	japanese-utf8
COLOR_STYLE_CONFIGURE_ENABLE=	color-style
DEFAULT_COLORS_CONFIGURE_ENABLE=default-colors

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET=	install-full
.else
INSTALL_TARGET=	install install-help
.endif

# Change "cd foo; $(MAKE_RECUR)" into "$(MAKE_RECUR) -C foo" to unbreak
# parallel builds
post-patch:
	@${REINPLACE_CMD} -E 's|cd (.+) && (\$$\(MAKE_RECUR\))|\2 -C \1|' \
		${WRKSRC}/${MAKEFILE}.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${L_HELP}

.include <bsd.port.mk>
