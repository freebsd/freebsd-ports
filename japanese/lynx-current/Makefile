# New ports collection makefile for:	ja-lynx-current
# Version required:     2.8.3dev.16
# Date created:         10 August 1998
# Whom:                 Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	lynx2.8.3dev.16
PKGNAME=	ja-lynx-2.8.3dev.16
CATEGORIES=	japanese www
MASTER_SITES=	${MASTER_SITE_PORTS_JP} \
		http://www.freebsd.org/~shige/ports/distfiles/ \
		http://sol.slcc.edu/lynx/current/

MAINTAINER=	shige@FreeBSD.org

USE_BZIP2=	YES
NO_LATEST_LINK=	YES
WRKSRC=		${WRKDIR}/lynx2-8-3
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-screen=ncurses --with-zlib \
		--libdir="${PREFIX}/${LYNX_LIB}" \
		--disable-nls --enable-default-colors \
		--enable-nsl-fork --enable-persistent-cookies \
		--enable-cjk --enable-file-upload --enable-justify-elts \
		--enable-libjs --enable-read-eta --enable-source-cache
# experimental optional configure args
#   --enable-prettysrc --enable-color-style
#
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
