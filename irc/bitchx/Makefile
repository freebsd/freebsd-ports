# New ports collection makefile for:	BitchX ircII client
# Date created:		26 Jan 1998
# Whom:			griffin
#
# $FreeBSD$
#

PORTNAME=	BitchX
PORTVERSION=	1.0c16
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.bitchx.com/pub/BitchX/source/ \
		ftp://ukug.uk.freebsd.org/pub/lord_cj/

MAINTAINER=	calle.madestrand@norrgarden.se

.if defined(WITH_GNOME)
LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs
.endif

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
WRKSRC=		${WRKDIR}/BitchX
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

pre-patch:
	@${PERL} -pi -e "s!#undef WANT_CHAN_NICK_SERV!#define WANT_CHAN_NICK_SERV!" ${WRKSRC}/include/config.h

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/bx/help
	${MKDIR} ${PREFIX}/share/doc/bitchx
	${CP} -r ${WRKSRC}/bitchx-docs/* ${PREFIX}/share/bx/help
	${INSTALL_DATA} ${WRKSRC}/doc/bxfaq.html ${PREFIX}/share/doc/bitchx
.endif
.if defined(WITH_GNOME)
	@${ECHO} bin/gtkBitchX >> ${TMPPLIST}
	@${ECHO} bin/gtkBitchX-1.0c16 >> ${TMPPLIST}
	@${ECHO} share/bx/plugins/nicklist.so >> ${TMPPLIST}
.else
	@${ECHO} bin/BitchX >> ${TMPPLIST}
	@${ECHO} bin/BitchX-1.0c16 >> ${TMPPLIST}
	@${ECHO} bin/scr-bx >> ${TMPPLIST}
	@${ECHO} share/bx/wserv >> ${TMPPLIST}
.endif
	@${ECHO} @dirrm share/bx/help >> ${TMPPLIST}
	@${ECHO} @dirrm share/bx/plugins >> ${TMPPLIST}
	@${ECHO} @dirrm share/bx/script >> ${TMPPLIST}
	@${ECHO} @dirrm share/bx/translation >> ${TMPPLIST}
	@${ECHO} @dirrm share/bx >> ${TMPPLIST}

.include <bsd.port.mk>
