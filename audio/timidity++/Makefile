# Created by: Yoichi Asai <yatt@luna2.org>
# $FreeBSD$

PORTNAME=	timidity++
PORTVERSION=	2.14.0
PORTREVISION?=	4
CATEGORIES+=	audio
MASTER_SITES=	SF/timidity/TiMidity%2B%2B/TiMidity%2B%2B-${PORTVERSION}
DISTNAME=	TiMidity++-${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Software MIDI player

LICENSE=	GPLv2+

.if !defined(PKGNAMESUFFIX)
LIB_DEPENDS=	libarc.so:archivers/libarc \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg
RUN_DEPENDS=	eawpats>0:audio/eawpats
.endif

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	SHLD="${CC} -shared"

CPPFLAGS+=	-I${LOCALBASE}/include/libarc -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,--export-dynamic

PLIST_SUB+=	TIMID_LIBDIR="${TIMID_LIBDIR}" EUCJP_LOCALE="${EUCJP_LOCALE}"

.if !defined(PKGNAMESUFFIX)
OPTIONS_DEFINE=		DOCS EAWPLUS X11
OPTIONS_DEFAULT=	X11
CONFIGURE_ARGS+=	--enable-audio=oss,vorbis
EAWPLUS_DESC=		Collection of Gravis Ultrasound MIDI patches
EAWPLUS_RUN_DEPENDS=	eawplus>0:audio/eawplus
X11_LIB_DEPENDS=	libpng.so:graphics/png
X11_USES=		xorg
X11_USE=		xorg=x11,xext
X11_CONFIGURE_ON=	--with-x --enable-spectrogram --enable-wrd \
			--enable-dynamic
X11_CONFIGURE_OFF=	--without-x --disable-spectrogram --disable-wrd \
			--disable-dynamic
X11_CPPFLAGS=		$$(libpng-config --I_opts)
.endif

TIMID_LIBDIR=	lib/timidity
EUCJP_LOCALE=	ja_JP.eucJP

.include <bsd.port.options.mk>

.if defined(PKGNAMESUFFIX)
.include "Makefile.interface"
.else
USES+=		ncurses
CONFIGURE_ARGS+=--enable-interface=ncurses,vt100,server \
		--enable-network

CONFLICTS_INSTALL=	timidity-[0-9]*

DOCFILES=	README.alsaseq README.dl README.m2m README.mts README.sf

pre-patch:
	@${RM} ${WRKSRC}/libarc/*.h
	@${RM} ${WRKSRC}/utils/mblock.h

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TIMID_LIBDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/timidity

post-install::
	(cd ${WRKSRC}/doc/ja_JP.eucJP && ${INSTALL_MAN} timidity.1 \
		${STAGEDIR}${MANPREFIX}/man/ja/man1)
	(cd ${WRKSRC}/doc/ja_JP.eucJP && ${INSTALL_MAN} timidity.cfg.5 \
		${STAGEDIR}${MANPREFIX}/man/ja/man5)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/C && ${INSTALL_DATA} ${DOCFILES} \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ja/${PORTNAME}
	(cd ${WRKSRC}/doc/ja_JP.eucJP && ${INSTALL_DATA} ${DOCFILES} \
		${STAGEDIR}${PREFIX}/share/doc/ja/${PORTNAME})
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/timidity

.endif # PKGNAMESUFFIX
.include <bsd.port.mk>
