# New ports collection makefile for:	TiMidity++
# Version required:	1.3.10
# Date created:		27 Feb 1999
# Whom:			Yoichi Asai <yatt@msc.biglobe.ne.jp>
#
# $FreeBSD$
#

DISTNAME=	TiMidity++-1.3.10
PKGNAME=	timidity++-tcltk-1.3.10
CATEGORIES=	audio
MASTER_SITES=	http://www.goice.co.jp/member/mo/timidity/dist/

MAINTAINER=	yatt@msc.biglobe.ne.jp

RUN_DEPENDS=	${PREFIX}/bin/timidity:${PORTSDIR}/audio/timidity++
LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80

USE_XLIB=	yes
USE_AUTOCONF=	yes

MASTERDIR=	${.CURDIR}/../../audio/timidity++ 
PKGDIR=		${.CURDIR}/pkg 

DIST_SUBDIR=	timidity

.include <bsd.port.pre.mk>

CONFIGURE_ARGS= --prefix=${PREFIX} --with-x \
		--disable-ncurses --disable-vt100 --enable-tcltk=dynamic \
		--disable-emacs --disable-xaw --disable-xskin \
		--disable-motif --disable-slang --disable-gtk \
		--enable-network --enable-spectrogram --enable-wrd \
		--with-tcl-includes=${PREFIX}/include/tcl8.0 \
		--with-tk-includes=${PREFIX}/include/tk8.0 \
		--with-tcl-libs=${PREFIX}/lib --with-tk-libs=${PREFIX}/lib
CONFIGURE_ENV=	WISH=wish8.0
.if ${PORTOBJFORMAT} == "elf"
CONFIGURE_ENV+=	LDFLAGS=-export-dynamic
.endif

TIMID_DIR=	${PREFIX}/lib/timidity
LINK=		tkmidi
DOCFILES=       README.tk
DOCLANG=	C

do-build:
	cd ${WRKSRC}/interface; ${MAKE}

do-install:
	cd ${WRKSRC}/interface; ${MAKE} ${INSTALL_TARGET}
	${LN} -sf ${PREFIX}/bin/timidity ${PREFIX}/bin/${LINK}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/timidity/C
	${INSTALL_DATA} ${WRKSRC}/doc/C/${DOCFILES} \
	${PREFIX}/share/doc/timidity/C
.endif

.include <bsd.port.post.mk>
