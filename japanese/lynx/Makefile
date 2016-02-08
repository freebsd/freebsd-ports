# Created by: Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lynx
DISTVERSION=	${VERSION}.${MINOR_VERSION:S/.//}
PORTREVISION=	2
CATEGORIES=	japanese www ipv6
MASTER_SITES=	http://invisible-mirror.net/archives/lynx/tarballs/
DISTNAME=	${PORTNAME}${VERSION}${MINOR_VERSION}

MAINTAINER=	CQG00620@nifty.ne.jp
COMMENT=	Console WWW client (browser) with multi-byte encoding support

LICENSE=	GPLv2

VERSION=	2.8.7
MINOR_VERSION=	rel.1

CONFLICTS=	lynx-2.* ja-lynx-2.8.8.*

USES=		cpe ncurses shebangfix tar:bzip2
SHEBANG_FILES=	samples/mailto-form.pl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-screen=ncurses --with-zlib --libdir="${L_LIB}" \
		--enable-nsl-fork --enable-ipv6 \
		--enable-cjk --enable-internal-links \
		--with-bzlib
MAKE_ARGS=	helpdir=${L_HELP} docdir=${DOCSDIR}
MAKEFILE=	makefile
INSTALL_TARGET=	install-full

WRKSRC=		${WRKDIR}/${PORTNAME}${VERSION:S/./-/g}
L_LIB=		${PREFIX}/etc
L_HELP=		${PREFIX}/share/lynx_help

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	JAPANESE_UTF8 COLOR_STYLE DEFAULT_COLORS DOCS
OPTIONS_SUB=	yes

JAPANESE_UTF8_DESC=	Experimental Japanese UTF-8 logic
COLOR_STYLE_DESC=	Color style (ncurses/curses)
DEFAULT_COLORS_DESC=	Default colors (ncurses/slang)

JAPANESE_UTF8_USES=		iconv
JAPANESE_UTF8_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG}
JAPANESE_UTF8_CONFIGURE_ENABLE=	japanese-utf8
COLOR_STYLE_CONFIGURE_ENABLE=	color-style
DEFAULT_COLORS_CONFIGURE_ENABLE=default-colors

# Change "cd foo && $(MAKE_RECUR)" into "$(MAKE_RECUR) -C foo" to unbreak
# parallel builds
post-patch:
	@${REINPLACE_CMD} -E 's|cd (.+) && (\$$\(MAKE_RECUR\))|\2 -C \1|' \
		${WRKSRC}/${MAKEFILE}.in

.include <bsd.port.mk>
