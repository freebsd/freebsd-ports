# New ports collection makefile for:	TiMidity++
# Date created:		27 Feb 1999
# Whom:			Yoichi Asai <yatt@luna2.org>
#
# $FreeBSD$
#

PORTNAME=	timidity++
PORTVERSION=	2.13.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=timidity
DISTNAME=	TiMidity++-${PORTVERSION}

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Software MIDI player

LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis	\
		arc:${PORTSDIR}/archivers/libarc
RUN_DEPENDS=	${LOCALBASE}/share/timidity/timidity.cfg:${PORTSDIR}/audio/eawpats

CONFLICTS=	timidity-0.*

# If you don't have X11, type "make -DWITHOUT_X11" or uncomment this.
#WITHOUT_X11=	yes
USE_BZIP2=	yes
USE_GETOPT_LONG=yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
EXTRACT_AFTER_ARGS=| ${TAR} -xpf - --exclude '*/libarc/*'	\
		--exclude '*/utils/mblock.h' --exclude '*/utils/memb.h'

CONFIGURE_ARGS?=--enable-interface=ncurses,vt100,server
CONFIGURE_ARGS+=--program-transform-name= --enable-network
CPPFLAGS+=	-I${LOCALBASE}/include/libarc
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS=-export-dynamic

PLIST_SUB=	EUCJP_LOCALE=${EUCJP_LOCALE} TIMID_LIBDIR=${TIMID_LIBDIR} \
		ELISPDIR=share/emacs/site-lisp

DOCFILES?=	README.alsaseq README.dl README.m2m README.mts README.sf
DOCLANG?=	C ja_JP.eucJP

TIMID_LIBDIR=	lib/timidity

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GMAKE=	yes
.endif

.if ${.CURDIR} == ${MASTERDIR}
MANLANG=	"" ja
MAN1=		timidity.1
MAN5=		timidity.cfg.5
.else
RUN_DEPENDS+=	${LOCALBASE}/bin/timidity:${PORTSDIR}/audio/timidity++
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--without-x --disable-spectrogram --disable-wrd --disable-dynamic
.else
CONFIGURE_ARGS+=--with-x    --enable-spectrogram  --enable-wrd  --enable-dynamic
USE_XLIB=	yes
LIB_DEPENDS+=	png:${PORTSDIR}/graphics/png
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

pre-install:
	@${MKDIR} ${PREFIX}/share/timidity ${PREFIX}/${TIMID_LIBDIR}

.if ${.CURDIR} == ${MASTERDIR}
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
.	for lang in ${DOCLANG}
	${MKDIR} ${PREFIX}/share/doc/${lang:C,^C$,,:C,ja_.*,ja/,}timidity++
	cd ${WRKSRC}/doc/${lang} && ${INSTALL_DATA} ${DOCFILES}	\
	    ${PREFIX}/share/doc/${lang:C,^C$,,:C,ja_.*,ja/,}timidity++/
.	endfor
.endif

.if defined(LINK)
post-install::
	${LN} -sf ${PREFIX}/bin/timidity ${PREFIX}/bin/${LINK}
.endif

.if exists(${PKGMESSAGE})
post-install::
	@${SED} -e 's,/usr/local,${PREFIX},g' ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
