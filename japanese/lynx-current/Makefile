# New ports collection makefile for:	ja-lynx-current
# Date created:         10 August 1998
# Whom:                 Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lynx
PORTVERSION=	${VERSION}.${MINOR_VERSION:S/.//}
CATEGORIES=	japanese www ipv6
MASTER_SITES=	${MASTER_SITE_PORTS_JP} \
		${MASTER_SITE_LOCAL} \
		http://lynx.isc.org/current/
MASTER_SITE_SUBDIR=	shige
DISTNAME=	${PORTNAME}${VERSION}${MINOR_VERSION}


MAINTAINER=	ports@FreeBSD.org
COMMENT=	A terminal-based World-Wide Web Client with multi-byte modification

WRKSRC=		${WRKDIR}/${PORTNAME}${VERSION:S/./-/g}

VERSION=	2.8.5
MINOR_VERSION=	dev.7

USE_BZIP2=	YES
NO_LATEST_LINK=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-screen=ncurses --with-zlib \
		--libdir="${PREFIX}/${LYNX_LIB}" \
		--disable-nls --enable-default-colors \
		--enable-nsl-fork --enable-persistent-cookies \
		--enable-cjk --enable-file-upload --enable-justify-elts \
		--enable-libjs --enable-read-eta --enable-source-cache \
		--enable-ipv6
.if (WITH_LYNX_EXPERIMENTAL_OPTS)
# experimental optional configure args
CONFIGURE_ARGS+=	--enable-prettysrc --enable-color-style \
			--enable-addrlist-page --enable-charset-choice \
			--enable-htmlized-cfg
.endif
MAKEFILE=	makefile
MAKE_ARGS=	helpdir=${PREFIX}/${LYNX_HELP} docdir=${PREFIX}/${LYNX_DOC}
PLIST_SUB=	LYNX_LIB=${LYNX_LIB} LYNX_DOC=${LYNX_DOC} LYNX_HELP=${LYNX_HELP}

INSTALL_TARGET=	install-full
MAN1=		lynx.1

LYNX_LIB=	etc
LYNX_DOC=	share/doc/lynx
LYNX_HELP=	share/lynx_help

post-install:
	@/usr/sbin/chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${LYNX_DOC}
	@/usr/sbin/chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${LYNX_HELP}
	@/usr/sbin/chown ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${LYNX_LIB}/lynx.cfg

.include <bsd.port.mk>
