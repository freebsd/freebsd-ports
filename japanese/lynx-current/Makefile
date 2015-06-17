# Created by: Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lynx
DISTVERSION=	${VERSION}.${MINOR_VERSION:S/.//}
PORTREVISION=	2
CATEGORIES=	japanese www ipv6
MASTER_SITES=	http://lynx.isc.org/current/ \
		http://ftp2.uk.freebsd.org/sites/lynx.isc.org/current/
DISTNAME=	${PORTNAME}${VERSION}${MINOR_VERSION}
PKGNAMESUFFIX=	-current

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Terminal WWW client with multi-byte modification (development version)

VERSION=	2.8.8
MINOR_VERSION=	dev.3

CONFLICTS=	lynx-2.* ja-lynx-2.8.7.*

WRKSRC=		${WRKDIR}/${PORTNAME}${VERSION:S/./-/g}
USES=		cpe shebangfix tar:bzip2
SHEBANG_FILES=	samples/mailto-form.pl
MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-screen=ncurses --with-zlib --libdir="${L_LIB}" \
		--enable-nsl-fork --enable-ipv6 \
		--enable-cjk --enable-internal-links \
		--with-bzlib
MAKE_ARGS=	helpdir=${L_HELP} docdir=${DOCSDIR}
MAKEFILE=	makefile
INSTALL_TARGET=	install-full

L_LIB=		${PREFIX}/etc
L_HELP=		${PREFIX}/share/lynx_help

OPTIONS_DEFINE=	COLOR_STYLE DEFAULT_COLORS DOCS EXPERIMENTAL_OPTS JAPANESE_UTF8
OPTIONS_DEFAULT=EXPERIMENTAL_OPTS JAPANESE_UTF8
OPTIONS_SUB=	yes

COLOR_STYLE_DESC=		Color style (ncurses/ncurses)
COLOR_STYLE_CONFIGURE_ENABLE=	color-style

DEFAULT_COLORS_DESC=		Default colors (ncurses/slang)
DEFAULT_COLORS_CONFIGURE_ENABLE=default-colors

EXPERIMENTAL_OPTS_DESC=		Experimental options
EXPERIMENTAL_OPTS_CONFIGURE_ON=	--enable-addrlist-page \
				--enable-charset-choice

JAPANESE_UTF8_DESC=		Experimental Japanese UTF-8 logic
JAPANESE_UTF8_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG} \
				--enable-japanese-utf8
JAPANESE_UTF8_CONFIGURE_OFF=	--disable-japanese-utf8
JAPANESE_UTF8_USES=		iconv

post-patch:
	@${REINPLACE_CMD} -e 's|-lssl -lcrypto|-L${OPENSSLLIB} &|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
