# New ports collection makefile for:	TiMidity++
# Date created:		27 Feb 1999
# Whom:			Yoichi Asai <yatt@luna2.org>
#
# $FreeBSD$
#

PORTNAME=	timidity++
PORTVERSION=	2.13.2
PORTREVISION=	1
CATEGORIES+=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=timidity
PKGNAMESUFFIX= -${INTERFACE}
DISTNAME=	TiMidity++-${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Emacs interface for TiMidity++

RUN_DEPENDS=	${LOCALBASE}/bin/timidity:${PORTSDIR}/audio/timidity++
LIB_DEPENDS=	${INTERFACE_DEPS}

SLAVEDIRS=	audio/timidity++-gtk audio/timidity++-motif \
		audio/timidity++-slang audio/timidity++-tcltk \
		audio/timidity++-xaw audio/timidity++-xskin \
		japanese/timidity++-slang japanese/timidity++-tcltk

INTERFACE?=	emacs

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
.if !${INTERFACE} == "emacs" && !${INTERFACE} == "slang"
USE_XLIB=	yes
.endif

CONFIGURE_ARGS+=--enable-dynamic=${INTERFACE}

MASTERDIR=	${.CURDIR}/../../audio/timidity++
PKGDIR=		${.CURDIR}
PLIST_SUB=	TIMID_LIBDIR=${TIMID_LIBDIR}

TIMID_LIBDIR=	${PREFIX}/lib/timidity

.if ${INTERFACE} == "emacs"
ELISPDIR=	${PREFIX}/share/emacs/site-lisp
.elif ${INTERFACE} == "gtk"
LINK=		gtkmidi
USE_GNOME=	gtk12
.elif ${INTERFACE} == "motif"
LINK=		xmmidi
USE_MOTIF=	yes
CONFIGURE_ENV+=	MOTIFLIB="${MOTIFLIB}"
.elif ${INTERFACE} == "slang"
CONFIGURE_ARGS+=--with-includes=${LOCALBASE}/include    \
		--with-libraries=${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
.if defined(JAPANESE)
INTERFACE_DEPS=	slang.2:${PORTSDIR}/japanese/libslang
.else
INTERFACE_DEPS=	slang:${PORTSDIR}/devel/libslang
.endif
CONFIGURE_ARGS+=	--enable-ncurses
.elif ${INTERFACE} == "tcltk"
LINK=		tkmidi
DOCFILES=	README.tk
DOCLANG=	C ja_JP.eucJP
.if defined(JAPANESE)
INTERFACE_DEPS=	tk80jp.1:${PORTSDIR}/japanese/tk80
CONFIGURE_ARGS+=	--with-tcl-includes=${PREFIX}/include/tcl8.0jp \
		--with-tk-includes=${PREFIX}/include/tk8.0jp \
		--with-tcl-libs=${PREFIX}/lib --with-tk-libs=${PREFIX}/lib
CONFIGURE_ENV+=	WISH=wish8.0jp
.else
INTERFACE_DEPS=	tk84:${PORTSDIR}/x11-toolkits/tk84
CONFIGURE_ARGS+=	--with-tcl-includes=${PREFIX}/include/tcl8.4 \
		--with-tk-includes=${PREFIX}/include/tk8.4 \
		--with-tcl-libs=${PREFIX}/lib --with-tk-libs=${PREFIX}/lib
CONFIGURE_ENV+=	WISH=wish8.4
.endif
.elif ${INTERFACE} == "xaw"
LINK=		xawmidi
DOCFILES=	README.xaw
DOCLANG=	C ja_JP.eucJP
INTERFACE_DEPS=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d
.elif ${INTERFACE} == "xskin"
LINK=		xskinmidi
DOCFILES=	README.xskin
DOCLANG=	C ja_JP.eucJP
.else
NO_BUILD=	yes
NO_INSTALL=	yes
.endif

CONFIGURE_ENV+=	SHLD="${CC} -shared ${LDFLAGS}"

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
LDFLAGS+=-export-dynamic
.endif

EUCJP_LOCALE=	ja_JP.eucJP
PLIST_SUB=	EUCJP_LOCALE=${EUCJP_LOCALE}

.if ${INTERFACE} == "motif"
post-configure:
	@${MV} ${WRKSRC}/interface/Makefile ${WRKSRC}/interface/Makefile.orig
	@${SED} -e 's^m_so_libs = $$^m_so_libs = -L${X11BASE}/lib ${MOTIFLIB} -lXt -lXext -lSM -lICE -lX11 ^' \
		-e 's^dynamic_targets = $$^dynamic_targets = interface_m.so^' \
	${WRKSRC}/interface/Makefile.orig > ${WRKSRC}/interface/Makefile
.endif

do-build:
	@cd ${WRKSRC}/interface; ${GMAKE} ${ALL_TARGET}

do-install:
	@cd ${WRKSRC}/interface; ${GMAKE} ${INSTALL_TARGET}

post-install:
.if ${INTERFACE} == "emacs"
	@${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/interface/timidity.el ${ELISPDIR}
.endif
.if ${INTERFACE} == "xaw"
	@${MKDIR} ${X11BASE}/lib/X11/${EUCJP_LOCALE}/app-defaults
	${INSTALL_DATA} ${WRKSRC}/TiMidity.ad \
	${X11BASE}/lib/X11/app-defaults/TiMidity
	${INSTALL_DATA} ${WRKSRC}/TiMidity-uj.ad \
	${X11BASE}/lib/X11/${EUCJP_LOCALE}/app-defaults/TiMidity
.endif
.if defined(DOCFILES) && !defined(NOPORTDOCS)
.for lang in ${DOCLANG}
	${MKDIR} ${PREFIX}/share/doc/${lang:C,^C$,,:C,ja_.*,ja/,}timidity++
	${INSTALL_DATA} ${WRKSRC}/doc/${lang}/${DOCFILES} \
	    ${PREFIX}/share/doc/${lang:C,^C$,,:C,ja_.*,ja/,}timidity++/
.endfor
.endif
.if defined(LINK)
	${LN} -sf ${PREFIX}/bin/timidity ${PREFIX}/bin/${LINK}
.endif
.if exists(${PKGMESSAGE})
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
