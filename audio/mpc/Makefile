# Created by: Mark Reidel <ports@mark.reidle.info>
# $FreeBSD$

PORTNAME=	mpc
PORTVERSION=	0.22
CATEGORIES=	audio ipv6
MASTER_SITES=	SF/musicpd/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	ports@mark.reidel.info
COMMENT=	Command line client for the musicpd

LICENSE=	GPLv2

LIB_DEPENDS=	mpdclient:${PORTSDIR}/audio/libmpdclient

OPTIONS_DEFINE=	EXAMPLES DOCS ICONV
OPTIONS_DEFAULT=	ICONV

USES=		pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

MAN1=		${PORTNAME}.1

PORTDOCS=	AUTHORS README NEWS
PORTEXAMPLES=	*

PLIST_FILES=	bin/${PORTNAME}

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
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}-completion.bash ${EXAMPLESDIR}
.endif

	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
