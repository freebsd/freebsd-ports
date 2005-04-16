# New ports collection makefile for:	TiMidity++
# Date created:		27 Feb 1999
# Whom:			Yoichi Asai <yatt@luna2.org>
#
# $FreeBSD$
#

PORTNAME=	timidity++
PORTVERSION=	2.13.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	timidity
DISTNAME=	TiMidity++-${PORTVERSION}

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Software MIDI player

LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis

CONFLICTS=	timidity-0.*

# If you don't have X11, type "make -DWITHOUT_X11" or uncomment this.
#WITHOUT_X11=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS?=--enable-interface=ncurses,vt100,server
CONFIGURE_ARGS+=--program-transform-name= --enable-network

.if ${CONFIGURE_ARGS:M*ncurses*} != ""
MANLANG=	"" ja
MAN1=		timidity.1
MAN5=		timidity.cfg.5
.else
RUN_DEPENDS+=	${LOCALBASE}/bin/timidity:${PORTSDIR}/audio/timidity++
.endif

PLIST_SUB=	EUCJP_LOCALE=${EUCJP_LOCALE} TIMID_LIBDIR=${TIMID_LIBDIR} \
		ELISPDIR=share/emacs/site-lisp

DOCFILES?=	README.alsaseq README.dl README.m2m README.mts README.sf
DOCLANG?=	C ja_JP.eucJP

TIMID_LIBDIR=	lib/timidity

.include <bsd.port.pre.mk>

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--without-x --disable-spectrogram --disable-wrd --disable-dynamic
.else
CONFIGURE_ARGS+=--with-x    --enable-spectrogram  --enable-wrd  --enable-dynamic
USE_XLIB=	yes
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
.endif

.if ${OSVERSION} >= 450002
EUCJP_LOCALE=	ja_JP.eucJP
.else
EUCJP_LOCALE=	ja_JP.EUC
.endif

#.if ${OSVERSION} > 600006
#BROKEN=		"Depends on libxpg4 which was removed from FreeBSD 6.0"
#.endif

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME=	esound
CONFIGURE_ARGS+=--enable-audio=oss,esd,vorbis
# 4.x make(1) doesn't like/work when using :=, so just disable esound suffix
#PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-esound
.else
CONFIGURE_ARGS+=--enable-audio=oss,vorbis
.endif

.if ${PORTOBJFORMAT} == "elf"
CONFIGURE_ENV=	LDFLAGS=-export-dynamic
.endif

pre-install:
.for dir in ${PREFIX}/share/timidity ${PREFIX}/${TIMID_LIBDIR}
	@[ -d ${dir} ] || ${MKDIR} ${dir}
.endfor

.if ${CONFIGURE_ARGS:M*ncurses*} != ""
post-install::
	${INSTALL_MAN} ${WRKSRC}/doc/ja_JP.eucJP/timidity.1 \
		${PREFIX}/man/ja/man1
	${INSTALL_MAN} ${WRKSRC}/doc/ja_JP.eucJP/timidity.cfg.5 \
		${PREFIX}/man/ja/man5
.else
do-build:
	@cd ${WRKSRC}/interface; ${MAKE} ${ALL_TARGET}

do-install:
	@cd ${WRKSRC}/interface; ${MAKE} ${INSTALL_TARGET}
.endif

.if !defined(NOPORTDOCS)
post-install::
.for lang in ${DOCLANG}
	${MKDIR} ${DOCSDIR}/`echo ${lang} | ${SED} -e 's/^C$$//' -e 's/_JP.eucJP$$//'`
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${lang}/${file} ${DOCSDIR}/`echo ${lang} | ${SED} -e 's/^C$$//' -e 's/_JP.eucJP$$//'`
.endfor
.endfor
.endif

.if defined(LINK)
post-install::
	${LN} -sf ${PREFIX}/bin/timidity ${PREFIX}/bin/${LINK}
.endif

.if exists(${PKGMESSAGE})
post-install::
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
