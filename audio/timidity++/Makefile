# New ports collection makefile for:	TiMidity++
# Date created:		27 Feb 1999
# Whom:			Yoichi Asai <yatt@luna2.org>
#
# $FreeBSD$
#

PORTNAME=	timidity++
PORTVERSION=	2.13.2
PORTREVISION?=	11
CATEGORIES+=	audio
MASTER_SITES=	SF/timidity/TiMidity%2B%2B/TiMidity%2B%2B-${PORTVERSION}
DISTNAME=	TiMidity++-${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Software MIDI player

.if !defined(PKGNAMESUFFIX)
LIB_DEPENDS=	vorbis:${PORTSDIR}/audio/libvorbis	\
		arc:${PORTSDIR}/archivers/libarc
RUN_DEPENDS=	${LOCALBASE}/share/timidity/timidity.cfg:${PORTSDIR}/audio/eawpats

CONFLICTS=	timidity-0.*
.endif

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_SUB+=	TIMID_LIBDIR=${TIMID_LIBDIR} EUCJP_LOCALE=${EUCJP_LOCALE}

EUCJP_LOCALE=	ja_JP.eucJP
TIMID_LIBDIR=	lib/timidity

.if !defined(PKGNAMESUFFIX)
WANT_GNOME=	yes
EXTRACT_AFTER_ARGS=| ${TAR} -xpf - --exclude '*/libarc/*'	\
		--exclude '*/utils/mblock.h' --exclude '*/utils/memb.h'

CONFIGURE_ARGS=	--enable-interface=ncurses,vt100,server \
		--program-transform-name= --enable-network
CPPFLAGS+=	-I${LOCALBASE}/include/libarc
LDFLAGS+=	-export-dynamic

DOCFILES=	README.alsaseq README.dl README.m2m README.mts README.sf
DOCLANG=	C ja_JP.eucJP

.include <bsd.port.pre.mk>

MANLANG=	"" ja
MAN1=		timidity.1
MAN5=		timidity.cfg.5

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--without-x --disable-spectrogram --disable-wrd --disable-dynamic
.else
CONFIGURE_ARGS+=--with-x    --enable-spectrogram  --enable-wrd  --enable-dynamic
USE_XORG=	x11 xext
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
CPPFLAGS+=	-I${LOCALBASE}/include/libpng15
.endif

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME=	esound
CONFIGURE_ARGS+=--enable-audio=oss,esd,vorbis
.else
CONFIGURE_ARGS+=--enable-audio=oss,vorbis
.endif

pre-su-install:
	@${MKDIR} ${PREFIX}/share/timidity ${PREFIX}/${TIMID_LIBDIR}

post-install::
	${INSTALL_MAN} ${WRKSRC}/doc/ja_JP.eucJP/timidity.1 \
		${PREFIX}/man/ja/man1
	${INSTALL_MAN} ${WRKSRC}/doc/ja_JP.eucJP/timidity.cfg.5 \
		${PREFIX}/man/ja/man5
.else # defined(PKGNAMESUFFIX)
.include "${MASTERDIR}/Makefile.interface"
.endif # !defined(PKGNAMESUFFIX)

post-install::
.if !defined(NOPORTDOCS) && defined(DOCFILES)
.for lang in ${DOCLANG}
	${MKDIR} ${PREFIX}/share/doc/${lang:C,^C$,,:C,ja_.*,ja/,}timidity++
	cd ${WRKSRC}/doc/${lang} && ${INSTALL_DATA} ${DOCFILES}	\
	    ${PREFIX}/share/doc/${lang:C,^C$,,:C,ja_.*,ja/,}timidity++/
.endfor
.endif
.if exists(${PKGMESSAGE})
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
