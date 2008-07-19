# New ports collection makefile for:	ja-lynx-current
# Date created:         10 August 1998
# Whom:                 Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lynx
PORTVERSION=	${VERSION}.${MINOR_VERSION:S/.//}
CATEGORIES=	japanese www ipv6
MASTER_SITES=	http://lynx.isc.org/current/ \
		http://ftp2.uk.freebsd.org/sites/lynx.isc.org/current/
DISTNAME=	${PORTNAME}${VERSION}${MINOR_VERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A terminal-based World-Wide Web Client with multi-byte modification (development version)

VERSION=	2.8.7
MINOR_VERSION=	dev.9

CONFLICTS=	lynx-2.* ja-lynx-2.8.6.*

WRKSRC=		${WRKDIR}/${PORTNAME}${VERSION:S/./-/g}
USE_BZIP2=	yes
NO_LATEST_LINK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-screen=ncurses --with-zlib --libdir="${L_LIB}" \
		--enable-nsl-fork --enable-ipv6 \
		--enable-cjk --enable-justify-elts --enable-internal-links \
		--with-bzlib

.ifndef (WITHOUT_LYNX_EXPERIMENTAL_OPTS)
# experimental optional configure args
USE_ICONV=	yes
CONFIGURE_ARGS+=--with-libiconv-prefix=${LOCALBASE} \
		--enable-japanese-utf8 --enable-addrlist-page \
		--enable-charset-choice
.endif

.if defined(ENABLE_COLOR_STYLE)
PLIST_SUB+=	ENABLE_COLOR_STYLE=""
.else
CONFIGURE_ARGS+=--disable-color-style
PLIST_SUB+=	ENABLE_COLOR_STYLE="@comment "
.endif

.if defined(ENABLE_DEFAULT_COLORS)
CONFIGURE_ARGS+=--enable-default-colors
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

post-patch:
	@${REINPLACE_CMD} -e 's|-lssl -lcrypto|-L${OPENSSLLIB} &|g' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${L_HELP}

.include <bsd.port.mk>
