# Created by: Mark Reidel <ports@mark.reidle.info>
# $FreeBSD$

PORTNAME=	musicpc
PORTVERSION=	0.25
CATEGORIES=	audio ipv6
MASTER_SITES=	http://musicpd.org/download/mpc/0/
DISTNAME=	mpc-${PORTVERSION}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Command line client for the musicpd

LICENSE=	GPLv2

LIB_DEPENDS=	libmpdclient.so:${PORTSDIR}/audio/libmpdclient

OPTIONS_DEFINE=	EXAMPLES DOCS ICONV
OPTIONS_DEFAULT=	ICONV

USES=		pkgconfig
USE_XZ=		yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/mpc man/man1/mpc.1.gz

PORTDOCS=	AUTHORS README NEWS
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
LDFLAGS+=	${ICONV_LIB}
.else
CONFIGURE_ARGS+=--disable-iconv
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lintl|${ICONV_LIB}|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mpc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/mpc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/mpc-completion.bash \
		${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
