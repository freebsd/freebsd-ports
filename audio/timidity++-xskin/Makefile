# New ports collection makefile for:	TiMidity++
# Version required:	1.3.10
# Date created:		27 Feb 1999
# Whom:			Yoichi Asai <yatt@msc.biglobe.ne.jp>
#
# $FreeBSD$
#

DISTNAME=	TiMidity++-1.3.10
PKGNAME=	timidity++-xskin-1.3.10
CATEGORIES=	audio
MASTER_SITES=	http://www.goice.co.jp/member/mo/timidity/dist/

MAINTAINER=	yatt@msc.biglobe.ne.jp

RUN_DEPENDS=	${PREFIX}/bin/timidity:${PORTSDIR}/audio/timidity++

# If you don't require Japanese docs, uncomment this.
#NO_USE_JAPANESE=	yes

USE_XLIB=	yes
USE_AUTOCONF=	yes

FILESDIR=	${.CURDIR}/../../audio/timidity++/files

DIST_SUBDIR=	timidity

.include <bsd.port.pre.mk>

CONFIGURE_ARGS= --prefix=${PREFIX} --with-x \
		--disable-ncurses --disable-vt100 --disable-tcltk \
		--disable-emacs --disable-xaw --enable-xskin=dynamic \
		--disable-motif --disable-slang --disable-gtk \
		--enable-network --enable-spectrogram --enable-wrd
.if ${PORTOBJFORMAT} == "elf"
CONFIGURE_ENV=	LDFLAGS=-export-dynamic
.endif

TIMID_DIR=	${PREFIX}/lib/timidity
LINK=		xskinmidi
DOCFILES=	README.xskin
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
	@cat ${PKGDIR}/MESSAGE

.include <bsd.port.post.mk>
