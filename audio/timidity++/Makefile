# New ports collection makefile for:	TiMidity++
# Date created:		27 Feb 1999
# Whom:			Yoichi Asai <yatt@msc.biglobe.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	timidity++
PORTVERSION=	2.10.4
CATEGORIES=	audio
MASTER_SITES=	http://www.goice.co.jp/member/mo/timidity/dist/
DISTNAME=	TiMidity++-${PORTVERSION}

MAINTAINER=	yatt@msc.biglobe.ne.jp

# If you don't have X11, type "make -DWITHOUT_X11" or uncomment this.
#WITHOUT_X11=	yes

SLAVEDIRS=	audio/timidity++-emacs
# rest are included by timidity++-emacs port
SLAVEDIRS+=	audio/timidity++-gtk audio/timidity++-motif \
		audio/timidity++-slang audio/timidity++-tcltk \
		audio/timidity++-xaw audio/timidity++-xskin \
		japanese/timidity++-slang japanese/timidity++-tcltk
USE_BZIP2=	yes
WANT_ESOUND=	yes
GNU_CONFIGURE=	yes
.if !defined(WITHOUT_X11)
USE_XLIB=	yes
LIB_DEPENDS+=	png.4:${PORTSDIR}/graphics/png
.endif

DIST_SUBDIR=	timidity
INSTALL_TARGET=	install install.man

.if !defined(WITHOUT_X11)
CONFIGURE_ARGS=	--with-x --enable-ncurses --enable-vt100 \
		--enable-dynamic --enable-server \
		--enable-network --enable-spectrogram --enable-wrd
.else
CONFIGURE_ARGS=	--enable-ncurses --enable-vt100 \
		--enable-network --disable-spectrogram --disable-wrd
.endif

MAN1=		timidity.1
MAN5=		timidity.cfg.5

MANLANG=	"" ja
DOCFILES=	README.dl README.sf
DOCLANG=	C ja_JP.ujis

.include <bsd.port.pre.mk>

.if defined(HAVE_ESOUND)
USE_ESOUND=	yes
CONFIGURE_ARGS+=--enable-audio=oss,esd
.else
CONFIGURE_ARGS+=--enable-audio=oss
.endif

.if ${PORTOBJFORMAT} == "elf"
CONFIGURE_ENV=	LDFLAGS=-export-dynamic
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/ja_JP.ujis/timidity.1 \
	${PREFIX}/man/ja/man1
	${INSTALL_MAN} ${WRKSRC}/doc/ja_JP.ujis/timidity.cfg.5 \
	${PREFIX}/man/ja/man5
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
	${SETENV} PKG_PREFIX=${PREFIX} \
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
