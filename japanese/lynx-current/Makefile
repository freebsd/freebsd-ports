# Created by: Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lynx
DISTVERSION=	${VERSION}.${MINOR_VERSION:S/.//}
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
USE_BZIP2=	yes
MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-screen=ncurses --with-zlib --libdir="${L_LIB}" \
		--enable-nsl-fork --enable-ipv6 \
		--enable-cjk --enable-internal-links \
		--with-bzlib

.if !defined(WITHOUT_JAPANESE_UTF8)
USES+=		iconv
CONFIGURE_ARGS+=${ICONV_CONFIGURE_ARG} \
		--enable-japanese-utf8
.else
CONFIGURE_ARGS+=--disable-japanese-utf8
.endif

.if !defined(WITHOUT_EXPERIMENTAL_OPTS)
# experimental optional configure args
CONFIGURE_ARGS+=--enable-addrlist-page \
		--enable-charset-choice
.endif

.if defined(WITH_COLOR_STYLE)
CONFIGURE_ARGS+=--enable-color-style
PLIST_SUB+=	WITH_COLOR_STYLE=""
.else
CONFIGURE_ARGS+=--disable-color-style
PLIST_SUB+=	WITH_COLOR_STYLE="@comment "
.endif

.if defined(WITH_DEFAULT_COLORS)
CONFIGURE_ARGS+=--enable-default-colors
.else
CONFIGURE_ARGS+=--disable-default-colors
.endif

MAKE_ARGS=	helpdir=${L_HELP} docdir=${DOCSDIR}
MAKEFILE=	makefile
MAN1=		lynx.1

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install-full
.else
INSTALL_TARGET=	install install-help
.endif

L_LIB=		${PREFIX}/etc
L_HELP=		${PREFIX}/share/lynx_help

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-lssl -lcrypto|-L${OPENSSLLIB} &|g' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${L_HELP}

.include <bsd.port.mk>
