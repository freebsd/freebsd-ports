# Created by: Jimbo Bahooli <griffin@blackhole.iceworld.org>
# $FreeBSD$

PORTNAME=	BitchX
DISTVERSION=	1.2-final
PORTEPOCH=	1
CATEGORIES+=	irc
MASTER_SITES=	http://bitchx.ca/

MAINTAINER?=	dan.mashal@gmail.com
# Co-maintainer: Chris Petrik <c.petrik.sosa@gmail.com> (PR/181627)
COMMENT?=	Feature-rich scriptable IRC client

WRKSRC=		${WRKDIR}/${DISTNAME:C,-final$,,}
USE_PERL5=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--exec-prefix="${PREFIX}/share" \
		--bindir="${PREFIX}/bin" \
		--datadir="${PREFIX}/share" \
		--libdir="${PREFIX}/share"
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"

PLIST_SUB+=	DISTVERSION=${DISTVERSION}
DOCSDIR=	${PREFIX}/share/bx/help
PORTDOCS=	*
DATADIR=	${PREFIX}/share/bx
MAN1=		BitchX.1

OPTIONS_DEFINE=	ESOUND GNOME IPV6 LATIN PLUGINS SSL XMMS

GNOME_DESC=	Legacy GTK/GNOME frontend
LATIN_DESC=	Recommended for ISO-8859-1 display
PLUGINS_DESC=	Build a handful of BitchX plugins
XMMS_DESC=	Build XMMS plugin

OPTIONS_DEFAULT=	IPV6 PLUGINS SSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--with-ssl
.endif

.if ${PORT_OPTIONS:MGNOME} || ${PORT_OPTIONS:MESOUND}
USE_GNOME=	gnomelibs
CONFIGURE_ARGS+=	--with-gtk
. if ${PORT_OPTIONS:MESOUND}
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--enable-sound
. endif
CFLAGS+=	-I${LOCALBASE}/include/gnome-1.0
PLIST_SUB+=	NOGNOME="@comment " GNOME=""
.else
CONFIGURE_ARGS+=	--without-gtk
PLIST_SUB+=	GNOME="@comment " NOGNOME=""
.endif

.if ${PORT_OPTIONS:MPLUGINS}
PLUGINS=	abot acro aim arcfour autocycle blowfish cavlink cdrom encrypt \
		europa fserv hint nap nicklist pkga possum qbx qmail wavplay
PLIST_SUB+=	PLUGINS=""
.else
PLIST_SUB+=	PLUGINS="@comment "
.endif

.if ${PORT_OPTIONS:MXMMS}
LIB_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
PLUGINS+=	xmms
PLIST_SUB+=	XMMS=""
.else
PLIST_SUB+=	XMMS="@comment "
.endif

.if !empty(PLUGINS)
CONFIGURE_ARGS+=	--with-plugins="${PLUGINS:C/\$$/,/g}"
.else
CONFIGURE_ARGS+=	--without-plugins
.endif

post-patch:
.if ${PORT_OPTIONS:MLATIN}
	${REINPLACE_CMD} -e 's|#undef LATIN1|#define LATIN1|' \
		${WRKSRC}/include/config.h
.endif
	${REINPLACE_CMD} -e 's|bzip2|true|g' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MGNOME}
	${STRIP_CMD} ${PREFIX}/bin/gtkBitchX
.else
	${STRIP_CMD} ${PREFIX}/bin/BitchX
	${STRIP_CMD} ${PREFIX}/bin/scr-bx
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/bitchx-docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

# Ensure that `@dirrm share/bx' will be appended last (after PORTDOCS stuff)
add-plist-post:
	@${ECHO_CMD} "@dirrm ${DATADIR_REL}" >> ${TMPPLIST}

.include <bsd.port.mk>
