# Created by: Jimbo Bahooli <griffin@blackhole.iceworld.org>
# $FreeBSD$

PORTNAME=	bitchx
PORTVERSION=	1.2.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES+=	irc
MASTER_SITES=	SF/${PORTNAME}/ircii-pana/${PORTNAME}-${DISTVERSION}

MAINTAINER=	freebsd@bitchx.org
COMMENT=	Feature-rich scriptable IRC client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		cpe gmake ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--exec-prefix="${PREFIX}/share" \
		--bindir="${PREFIX}/bin" \
		--datadir="${PREFIX}/share" \
		--libdir="${PREFIX}/share"
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_SUB=	yes

PLIST_SUB+=	DISTVERSION=${DISTVERSION}
DOCSDIR=	${PREFIX}/share/bx/help
PORTDOCS=	*
DATADIR=	${PREFIX}/share/bx

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS HEBREW IPV6 LATIN PLUGINS SSL TOGGLES

LATIN_DESC=	Recommended for ISO-8859-1 display
PLUGINS_DESC=	Build a handful of BitchX plugins
HEBREW_DESC=	Add support for hebrew language
TOGGLES_DESC=	Disable annoyance toggles
OPTIONS_DEFAULT=	PLUGINS SSL

IPV6_CONFIGURE_ENABLE=	ipv6

SSL_CONFIGURE_WITH=	ssl
SSL_USE=	openssl=yes

PLUGINS_CONFIGURE_WITH=		plugins="${PLUGIN_LIST:C/\$$/,/g}"

PLUGIN_LIST=	abot acro arcfour autocycle blowfish cavlink cdrom encrypt \
		europa fserv hint nap nicklist pkga possum qbx qmail wavplay
.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MLATIN}
	${REINPLACE_CMD} -e 's|#undef LATIN1|#define LATIN1|' \
		${WRKSRC}/include/config.h
.endif
.if ${PORT_OPTIONS:MHEBREW}
	${REINPLACE_CMD} -e 's|#undef WANT_HEBREW|#define WANT_HEBREW|' \
		${WRKSRC}/include/config.h
.endif
.if ${PORT_OPTIONS:MTOGGLES}
	${REINPLACE_CMD} -e 's|DEFAULT_AUTO_AWAY ON|DEFAULT_AUTO_AWAY OFF|' \
		${WRKSRC}/include/config.h
	${REINPLACE_CMD} -e 's|DEFAULT_KICK_OPS ON|DEFAULT_KICK_OPS OFF|' \
		${WRKSRC}/include/config.h
	${REINPLACE_CMD} -e 's|DEFAULT_AUTO_REJOIN ON|DEFAULT_AUTO_REJOIN OFF|' \
		${WRKSRC}/include/config.h
.endif
	${REINPLACE_CMD} -e 's|bzip2|true|g' ${WRKSRC}/Makefile.in

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/bitchx-docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSSL} && ${SSL_DEFAULT:Mopenssl-devel}
BROKEN=		Does not build with openssl-devel
.endif

.include <bsd.port.post.mk>
