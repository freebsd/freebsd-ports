# New ports collection makefile for:	TiMidity++
# Version required:	1.3.10
# Date created:		27 Feb 1999
# Whom:			Yoichi Asai <yatt@msc.biglobe.ne.jp>
#
# $FreeBSD$
#

DISTNAME=	TiMidity++-1.3.10
PKGNAME=	ja-timidity++-tcltk-1.3.10
CATEGORIES=	japanese audio
MASTER_SITES=	http://www.goice.co.jp/member/mo/timidity/dist/

MAINTAINER=	yatt@msc.biglobe.ne.jp

RUN_DEPENDS=	${PREFIX}/bin/timidity:${PORTSDIR}/audio/timidity++
LIB_DEPENDS=	tk80jp.1:${PORTSDIR}/japanese/tk80

# If you don't require Japanese docs, uncomment this.
#NO_USE_JAPANESE=	yes

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
		--enable-network --enable-spectrogram --enable-wrd
CONFIGURE_ARGS+=	--with-tcl-includes=${PREFIX}/include/tcl8.0jp \
		--with-tk-includes=${PREFIX}/include/tk8.0jp \
		--with-tcl-libs=${PREFIX}/lib --with-tk-libs=${PREFIX}/lib
CONFIGURE_ENV=	WISH=wish8.0jp
.if ${PORTOBJFORMAT} == "elf"
CONFIGURE_ENV+=	LDFLAGS=-export-dynamic
.endif

TIMID_DIR=	${PREFIX}/lib/timidity
LINK=		tkmidi
DOCFILES=	README.tk
DOCLANG=	C
.if !defined(NO_USE_JAPANESE)
DOCLANG+=	ja_JP.ujis
.endif

do-build:
	cd ${WRKSRC}/interface; ${MAKE}

do-install:
	cd ${WRKSRC}/interface; ${MAKE} ${INSTALL_TARGET}
	${LN} -sf ${PREFIX}/bin/timidity ${PREFIX}/bin/${LINK}

post-install:
.if !defined(NOPORTDOCS)
.for lang in ${DOCLANG}
	@${MKDIR} \
	${PREFIX}/share/doc/timidity/`echo ${lang} | ${SED} 's/_JP.ujis//'`
	${INSTALL_DATA} ${WRKSRC}/doc/${lang}/${DOCFILES} \
	${PREFIX}/share/doc/timidity/`echo ${lang} | ${SED} 's/_JP.ujis//'`
.endfor
.endif

.include <bsd.port.post.mk>
