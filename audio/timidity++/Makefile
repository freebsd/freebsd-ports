# New ports collection makefile for:	TiMidity++
# Version required:	1.3.10
# Date created:		27 Feb 1999
# Whom:			Yoichi Asai <yatt@msc.biglobe.ne.jp>
#
# $FreeBSD$
#

DISTNAME=	TiMidity++-1.3.10
PKGNAME=	timidity++-1.3.10
CATEGORIES=	audio
MASTER_SITES=	http://www.goice.co.jp/member/mo/timidity/dist/

MAINTAINER=	yatt@msc.biglobe.ne.jp

# If you don't have X11, type "make -DNO_X11" or uncomment this.
#NO_X11=	yes

# If you don't require Japanese docs, uncomment this.
#NO_USE_JAPANESE=	yes

.if !defined(NO_X11)
USE_XLIB=	yes
.endif
USE_AUTOCONF=	yes

DIST_SUBDIR=	timidity

PLIST_SUB=	TIMID_DIR=${TIMID_DIR}

.include <bsd.port.pre.mk>

.if !defined(NO_X11)
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-x --enable-audio \
		--enable-ncurses --enable-vt100 \
		--enable-dynamic=dynamic \
		--enable-network --enable-spectrogram --enable-wrd
.else
CONFIGURE_ARGS= --prefix=${PREFIX} --enable-audio \
		--enable-ncurses --enable-vt100 \
		--disable-tcltk --disable-emacs --disable-xaw --disable-xskin \
		--disable-motif --disable-slang --disable-gtk \
		--enable-network --disable-spectrogram --disable-wrd
.endif
.if ${PORTOBJFORMAT} == "elf"
CONFIGURE_ENV= LDFLAGS=-export-dynamic
.endif

MAN1=		timidity.1
MAN5=		timidity.cfg.5
MANLANG=	""
.if !defined(NO_USE_JAPANESE)
MANLANG+=	ja
.endif

DOCFILES=	README.dl README.sf
DOCLANG=	C
.if !defined(NO_USE_JAPANESE)
DOCLANG+=	ja_JP.ujis
.endif

TIMID_DIR=	${PREFIX}/lib/timidity

post-install:
	@${MKDIR} ${TIMID_DIR}
.if !defined(NOPORTDOCS)
.for lang in ${DOCLANG}
	@${MKDIR} \
	${PREFIX}/share/doc/timidity/`echo ${lang} | ${SED} 's/_JP.ujis//'`
	for f in ${DOCFILES}; do \
	${INSTALL_DATA} ${WRKSRC}/doc/${lang}/$$f \
	${PREFIX}/share/doc/timidity/`echo ${lang} | ${SED} 's/_JP.ujis//'`; \
	done;
.endfor
.endif
.if !defined(NO_USE_JAPANESE)
	@${MKDIR} ${PREFIX}/man/ja/man1; ${MKDIR} ${PREFIX}/man/ja/man5
	${INSTALL_MAN} ${WRKSRC}/doc/ja_JP.ujis/timidity.1 \
	${PREFIX}/man/ja/man1
	${INSTALL_MAN} ${WRKSRC}/doc/ja_JP.ujis/timidity.cfg.5 \
	${PREFIX}/man/ja/man5
.endif

.include <bsd.port.post.mk>
