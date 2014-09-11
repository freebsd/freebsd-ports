# Created by: Jimbo Bahooli <griffin@blackhole.iceworld.org>
# $FreeBSD$

PORTNAME=	BitchX
DISTVERSION=	1.2-final
PORTREVISION?=	2
PORTEPOCH=	1
CATEGORIES+=	irc
MASTER_SITES=	http://bitchx.ca/

MAINTAINER?=	dan.mashal@gmail.com
# Co-maintainer: Chris Petrik <c.petrik.sosa@gmail.com> (PR/181627)
COMMENT?=	Feature-rich scriptable IRC client

WRKSRC=		${WRKDIR}/${DISTNAME:C,-final$,,}

USES=		gmake perl5
USE_GCC=	yes # PR: 186425
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--exec-prefix="${PREFIX}/share" \
		--bindir="${PREFIX}/bin" \
		--datadir="${PREFIX}/share" \
		--libdir="${PREFIX}/share"
LIBS+=		-L${LOCALBASE}/lib

PLIST_SUB+=	DISTVERSION=${DISTVERSION}
DOCSDIR=	${PREFIX}/share/bx/help
PORTDOCS=	*
DATADIR=	${PREFIX}/share/bx

OPTIONS_DEFINE=	IPV6 LATIN PLUGINS SSL DOCS

LATIN_DESC=	Recommended for ISO-8859-1 display
PLUGINS_DESC=	Build a handful of BitchX plugins

OPTIONS_DEFAULT=PLUGINS SSL

MAKE_JOBS_UNSAFE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--with-ssl
.endif

.if ${PORT_OPTIONS:MPLUGINS}
PLUGINS=	abot acro aim arcfour autocycle blowfish cavlink cdrom encrypt \
		europa fserv hint nap nicklist pkga possum qbx qmail wavplay
PLIST_SUB+=	PLUGINS=""
.else
PLIST_SUB+=	PLUGINS="@comment "
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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/BitchX
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/scr-bx
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/bitchx-docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif

# Ensure that `@dirrm share/bx' will be appended last (after PORTDOCS stuff)
add-plist-post:
	@${ECHO_CMD} "@dirrm ${DATADIR_REL}" >> ${TMPPLIST}

.include <bsd.port.mk>
