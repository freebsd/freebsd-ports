# New ports collection makefile for:	BitchX ircII client patched for korean
# Date created:		3 Jun 1999
# Whom:			JunSeon Oh <hollywar@mail.holywar.net>
#
# $FreeBSD$
#

PORTNAME=	BitchX
PORTVERSION=	1.0c16
CATEGORIES=	korean irc gnome
MASTER_SITES=	ftp://ftp.bitchx.com/pub/BitchX/source/ \
		ftp://ukug.uk.freebsd.org/pub/lord_cj/

PATCH_SITES=    ftp://ftp.holywar.net/pub/FreeBSD/
PATCHFILES=     bx-korean-aa.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hollywar@mail.holywar.net

.if defined(WITH_GNOME)
LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs
.endif

#PATCH_DIST_ARGS=       -d ${WRKDIR}/ --forward --quiet -E ${PATCH_DIST_STRIP}
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
WRKSRC=         ${WRKDIR}/BitchX
USE_AUTOCONF=	yes
USE_GMAKE=	yes
.if defined(WITH_GNOME)
CONFIGURE_ARGS+=	--with-plugins --with-gtk --enable-sound
.else
CONFIGURE_ARGS+=	--with-plugins --without-gtk
.endif
CONFIGURE_ARGS+=	--exec-prefix="${PREFIX}/share"	\
			--bindir="${PREFIX}/bin" \
			--datadir="${PREFIX}/share" \
			--libdir="${PREFIX}/share"

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}"

MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

.if !defined(WITH_GNOME)
pre-extract:
	@${ECHO} "You can add hooks for GNOME by defining WITH_GNOME"
.endif

post-install:
	@(${LN} -sf ${PREFIX}/bin/BitchX ${PREFIX}/bin/bx)
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/bx/help
	${MKDIR} ${PREFIX}/share/doc/bitchx
	${CP} -r ${WRKSRC}/bitchx-docs/* ${PREFIX}/share/bx/help
	${INSTALL_DATA} ${WRKSRC}/doc/bxfaq.html ${PREFIX}/share/doc/bitchx
	${RMDIR} ${PREFIX}/share/bx/help/4_Misc/fset
	${RMDIR} ${PREFIX}/share/bx/help/4_Misc/wset
.endif
.if defined(WITH_GNOME)
	@${ECHO} bin/gtkBitchX >> ${TMPPLIST}
	@${ECHO} bin/gtkBitchX-1.0c16+H1 >> ${TMPPLIST}
	@${ECHO} share/bx/plugins/nicklist.so >> ${TMPPLIST}
.else
	@${ECHO} bin/bx >> ${TMPPLIST}
	@${ECHO} bin/BitchX >> ${TMPPLIST}
	@${ECHO} bin/BitchX-1.0c16+H1 >> ${TMPPLIST}
	@${ECHO} bin/scr-bx >> ${TMPPLIST}
	@${ECHO} share/bx/wserv >> ${TMPPLIST}
.endif
	@${ECHO} @dirrm share/bx/help >> ${TMPPLIST}
	@${ECHO} @dirrm share/bx/plugins >> ${TMPPLIST}
	@${ECHO} @dirrm share/bx/script >> ${TMPPLIST}
	@${ECHO} @dirrm share/bx/translation >> ${TMPPLIST}
	@${ECHO} @dirrm share/bx >> ${TMPPLIST}

.include <bsd.port.mk>
