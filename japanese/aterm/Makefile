# New ports collection makefile for:	ja-aterm
# Date Created:		17 Mar 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	aterm
PORTVERSION=	0.4.2
CATEGORIES+=	japanese x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

PATCH_SITES=	http://wakaba.com/~tsann/aterm/
PATCHFILES=	${DISTNAME}-ja.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	yoichi@FreeBSD.org
COMMENT=	A color vt102 terminal emulator with transparency support

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

WANT_AUTOCONF_VER=253
USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?= \
		--enable-transparency --enable-background-image \
		--enable-fading --enable-utmp --enable-wtmp \
		--enable-kanji --enable-linespace --enable-xim

.if defined(WITH_MENUBAR)
CONFIGURE_ARGS+= --enable-menubar
.endif

MAN1=		aterm.1

pre-configure:
	@(cd ${WRKSRC}; \
	${AUTOHEADER} --localdir=autoconf autoconf/configure.in > autoconf/config.h.in; \
	${AUTOCONF} --localdir=autoconf autoconf/configure.in > configure)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/aterm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/aterm.1 ${PREFIX}/man/man1/
	@${CHMOD} 4711 ${PREFIX}/bin/aterm

.include <bsd.port.mk>
