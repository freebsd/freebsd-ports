# New ports collection makefile for:	TiMidity++
# Version required:	1.3.10
# Date created:		27 Feb 1999
# Whom:			Yoichi Asai <yatt@msc.biglobe.ne.jp>
#
# $FreeBSD$
#

DISTNAME=	TiMidity++-1.3.10
PKGNAME=	timidity++-emacs-1.3.10
CATEGORIES=	audio
MASTER_SITES=	http://www.goice.co.jp/member/mo/timidity/dist/

MAINTAINER=	yatt@msc.biglobe.ne.jp

RUN_DEPENDS=	${PREFIX}/bin/timidity:${PORTSDIR}/audio/timidity++

USE_XLIB=	yes
USE_AUTOCONF=	yes

FILESDIR=	${.CURDIR}/../../audio/timidity++/files

DIST_SUBDIR=	timidity

.include <bsd.port.pre.mk>

CONFIGURE_ARGS= --prefix=${PREFIX} --with-x \
		--disable-ncurses --disable-vt100 --disable-tcltk \
		--enable-emacs=dynamic --disable-xaw --disable-xskin \
		--disable-motif --disable-slang --disable-gtk \
		--enable-network --enable-spectrogram --enable-wrd
.if ${PORTOBJFORMAT} == "elf"
CONFIGURE_ENV=	LDFLAGS=-export-dynamic
.endif

TIMID_DIR=	${PREFIX}/lib/timidity

do-build:
	cd ${WRKSRC}/interface; ${MAKE}

do-install:
	cd ${WRKSRC}/interface; ${MAKE} ${INSTALL_TARGET}
	${INSTALL_DATA} ${WRKSRC}/interface/timidity.el ${TIMID_DIR}
	@cat ${PKGDIR}/MESSAGE

.include <bsd.port.post.mk>
