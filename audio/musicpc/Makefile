# Created by: Mark Reidel <ports@mark.reidle.info>
# $FreeBSD$

PORTNAME=	musicpc
PORTVERSION=	0.22
CATEGORIES=	audio ipv6
MASTER_SITES=	SF/musicpd/mpc/${PORTVERSION}/
DISTNAME=	mpc-${PORTVERSION}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Command line client for the musicpd

LICENSE=	GPLv2

LIB_DEPENDS=	libmpdclient.so:${PORTSDIR}/audio/libmpdclient

OPTIONS_DEFINE=	EXAMPLES DOCS ICONV
OPTIONS_DEFAULT=	ICONV

USES=		pkgconfig
NO_STAGE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

MAN1=		mpc.1

PORTDOCS=	AUTHORS README NEWS
PORTEXAMPLES=	*

PLIST_FILES=	bin/mpc

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
	${INSTALL_PROGRAM} ${WRKSRC}/src/mpc ${PREFIX}/bin

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/mpc-completion.bash ${EXAMPLESDIR}
.endif

	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
