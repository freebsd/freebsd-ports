# New ports collection makefile for:	TiMidity++
# Version required:	1.3.10
# Date created:		27 Feb 1999
# Whom:			Yoichi Asai <yatt@msc.biglobe.ne.jp>
#
# $FreeBSD$
#

DISTNAME=	TiMidity++-1.3.10
PKGNAME=	timidity++-motif-1.3.10
CATEGORIES=	audio
MASTER_SITES=	http://www.goice.co.jp/member/mo/timidity/dist/

MAINTAINER=	yatt@msc.biglobe.ne.jp

RUN_DEPENDS=	${PREFIX}/bin/timidity:${PORTSDIR}/audio/timidity++

USE_XLIB=	yes
USE_AUTOCONF=	yes
REQUIRES_MOTIF=	yes

FILESDIR=	${.CURDIR}/../../audio/timidity++/files

DIST_SUBDIR=	timidity

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--prefix=${PREFIX} --with-x \
		--disable-ncurses --disable-vt100 --disable-tcltk \
		--disable-emacs --disable-xaw --disable-xskin \
		--enable-motif=dynamic --disable-slang --disable-gtk \
		--enable-network --enable-spectrogram --enable-wrd
CONFIGURE_ENV=	MOTIFLIB="${MOTIFLIB}"
.if ${PORTOBJFORMAT} == "elf"
CONFIGURE_ENV+=	LDFLAGS=-export-dynamic
.endif

TIMID_DIR=	${PREFIX}/lib/timidity
LINK=		xmmidi

do-build:
	cd ${WRKSRC}/interface; ${MAKE}

do-install:
	cd ${WRKSRC}/interface; ${MAKE} ${INSTALL_TARGET}
	${LN} -sf ${PREFIX}/bin/timidity ${PREFIX}/bin/${LINK}

.include <bsd.port.post.mk>
