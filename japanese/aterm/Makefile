# New ports collection makefile for:	ja-aterm
# Date Created:		17 Mar 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	aterm
PORTVERSION=	0.4.2
PORTREVISION=	7
CATEGORIES+=	japanese x11
MASTER_SITES=	SF

PATCH_SITES=	http://www.jaist.ac.jp/~amatsus/linux/src/xfree86/aterm/
PATCHFILES=	${DISTNAME}-xim.patch.gz \
		${DISTNAME}-compoundtext.patch.gz \
		${DISTNAME}-linespace.patch.gz

PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A color vt102 terminal emulator with transparency support

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png

USE_AUTOTOOLS=	autoconf:262:env
USE_XORG=	xpm xmu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?= \
		--enable-transparency --enable-background-image \
		--enable-fading --enable-utmp --enable-wtmp \
		--enable-kanji --enable-linespace --enable-xim

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

.if defined(WITH_MENUBAR)
CONFIGURE_ARGS+= --enable-menubar
.endif

MAN1=		aterm.1

pre-configure:
	@(cd ${WRKSRC}; \
	${AUTOCONF} --include=autoconf autoconf/configure.in > configure)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/aterm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/aterm.1 ${PREFIX}/man/man1/
	@${CHMOD} 4711 ${PREFIX}/bin/aterm

.include <bsd.port.post.mk>
