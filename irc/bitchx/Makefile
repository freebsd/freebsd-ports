# New ports collection makefile for:	BitchX ircII client
# Date created:		26 Jan 1998
# Whom:			griffin
#
# $FreeBSD$
#

PORTNAME=	BitchX
PORTVERSION=	1.0c17
CATEGORIES=	irc gnome
MASTER_SITES=	ftp://ftp.bitchx.com/pub/BitchX/source/ \
		ftp://ftp.bitchx.org/pub/BitchX/source/

MAINTAINER=	cj@vallcom.net

.if defined(WITH_GNOME)
LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs
.endif

.if defined(WITH_TCL)
BUILD_DEPENDS=	${LOCALBASE}/include/tcl8.3/tcl.h:${PORTSDIR}/lang/tcl83
.endif

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
WRKSRC=		${WRKDIR}/BitchX
USE_AUTOCONF=	yes
USE_GMAKE=	yes
.if defined(WITH_GNOME)
CONFIGURE_ARGS+=	--with-gtk
.else
CONFIGURE_ARGS+=	--without-gtk
.endif
.if defined(WITH_TCL)
CONFIGURE_ARGS+=	--with-tcl \
			--with-tcl-includes=/usr/local/include/tcl8.3 \
			--with-tcl-libs=/usr/local/lib
.endif
.if defined(WITH_ESD)
CONFIGURE_ARGS+=	--enable-sound
.endif
.if defined(WITH_PLUGINS)
CONFIGURE_ARGS+=	--with-plugins=pkga,possum,encrypt,hint,abot,acro,amp,blowfish,scan,wavplay,qmail,fserv,nap,qbx
.else
CONFIGURE_ARGS+=	--without-plugins
.endif
CONFIGURE_ARGS+=	--exec-prefix="${PREFIX}/share"	\
			--bindir="${PREFIX}/bin" \
			--datadir="${PREFIX}/share" \
			--libdir="${PREFIX}/share"

.if defined(WITH_TCL)
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.3"
.else
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
.endif
CONFIGURE_ENV+= GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}"

MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

pre-extract:
	@${CAT} ${PKGDIR}/MESSAGE

.if defined(WITH_TCL)
post-extract:
	@uudecode -p files/tcl-freebsd.o.uu > ${WRKSRC}/source/tcl.o
.endif

.if defined(WITH_LATIN)
pre-patch:
	@${PERL} -pi -e "s!#undef LATIN1!#define LATIN1!" ${WRKSRC}/include/config.h
.endif
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/bx/help
	${MKDIR} ${PREFIX}/share/doc/bitchx
	${TAR} --directory ${WRKSRC}/bitchx-docs -cf - . --exclude CVS | \
	${TAR} --directory ${PREFIX}/share/bx/help -xf -
	${INSTALL_DATA} ${WRKSRC}/doc/bxfaq.html ${PREFIX}/share/doc/bitchx
.endif

.if defined(WITH_PLUGINS)
	@${ECHO} share/bx/plugins/BitchX.hints >> ${TMPPLIST}
	@${ECHO} share/bx/plugins/acro.so >> ${TMPPLIST}
	@${ECHO} share/bx/plugins/amp.so >> ${TMPPLIST}
	@${ECHO} share/bx/plugins/autobot.so >> ${TMPPLIST}
	@${ECHO} share/bx/plugins/blowfish.so >> ${TMPPLIST}
	@${ECHO} share/bx/plugins/encrypt.so >> ${TMPPLIST}
	@${ECHO} share/bx/plugins/fserv.so >> ${TMPPLIST}
	@${ECHO} share/bx/plugins/hint.so >> ${TMPPLIST}
	@${ECHO} share/bx/plugins/nap.so >> ${TMPPLIST}
	@${ECHO} share/bx/plugins/pkga.so >> ${TMPPLIST}
	@${ECHO} share/bx/plugins/possum.so >> ${TMPPLIST}
	@${ECHO} share/bx/plugins/qmail.so >> ${TMPPLIST}
	@${ECHO} share/bx/plugins/scan.so >> ${TMPPLIST}
	@${ECHO} share/bx/plugins/wavplay.so >> ${TMPPLIST}
	@${ECHO} share/bx/plugins/qbx.so >> ${TMPPLIST}
	@${ECHO} @dirrm share/bx/plugins >> ${TMPPLIST}
.endif
.if defined(WITH_GNOME)
	@${ECHO} bin/gtkBitchX >> ${TMPPLIST}
	@${ECHO} bin/gtkBitchX-1.0c17 >> ${TMPPLIST}
.else
	@${ECHO} bin/BitchX >> ${TMPPLIST}
	@${ECHO} bin/BitchX-1.0c17 >> ${TMPPLIST}
	@${ECHO} bin/scr-bx >> ${TMPPLIST}
	@${ECHO} share/bx/wserv >> ${TMPPLIST}
.endif
	@${ECHO} @dirrm share/bx/help >> ${TMPPLIST}
	@${ECHO} @dirrm share/bx/script >> ${TMPPLIST}
	@${ECHO} @dirrm share/bx/translation >> ${TMPPLIST}
	@${ECHO} @dirrm share/bx >> ${TMPPLIST}

.include <bsd.port.mk>
