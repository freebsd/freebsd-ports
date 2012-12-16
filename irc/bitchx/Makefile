# Created by: Jimbo Bahooli <griffin@blackhole.iceworld.org>
# $FreeBSD$

PORTNAME=	BitchX
PORTVERSION=	1.1.0.1
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES+=	irc
MASTER_SITES=	SF/bitchx/ircii-pana/ircii-pana-1.1
DISTNAME=	ircii-pana-1.1-final

MAINTAINER?=	dan.mashal@gmail.com
COMMENT?=	Feature-rich scriptable IRC client

WRKSRC=		${WRKDIR}/BitchX
USE_PERL5=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_GMAKE=	yes
DOCSDIR=	${PREFIX}/share/bx/help
PORTDOCS=	*
CONFIGURE_ARGS+=--exec-prefix="${PREFIX}/share" \
		--bindir="${PREFIX}/bin" \
		--datadir="${PREFIX}/share" \
		--libdir="${PREFIX}/share"
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

MAN1=		BitchX.1

OPTIONS_DEFINE=	ESOUND GNOME IPV6 LATIN PLUGINS SSL XMMS

GNOME_DESC=	Legacy GTK/GNOME frontend
LATIN_DESC=	Recommended for ISO-8859-1 display
PLUGINS_DESC=	Build a handful of BitchX plugins
XMMS_DESC=	Build XMMS plugin

OPTIONS_DEFAULT=	IPV6 PLUGINS SSL

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

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
PLUGINS=	abot acro arcfour autocycle blowfish cdrom encrypt scan \
		europa fserv hint nicklist pkga possum qbx qmail wavplay
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
	${STRIP_CMD} ${PREFIX}/bin/gtkBitchX-1.1-final
.else
	${STRIP_CMD} ${PREFIX}/bin/BitchX-1.1-final
	${STRIP_CMD} ${PREFIX}/bin/scr-bx
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/bitchx-docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

add-plist-post:
	@${ECHO_CMD} "@dirrm share/bx" >> ${TMPPLIST}
.if (${PREFIX} != ${LOCALBASE} && ${PREFIX} != ${LINUXBASE} && ${PREFIX} != "/usr")
	@${ECHO_CMD} "@unexec rmdir %D 2> /dev/null || true" >> ${TMPPLIST}
.else
	@${DO_NADA}
.endif

.include <bsd.port.post.mk>
