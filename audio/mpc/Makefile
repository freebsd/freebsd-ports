# Created by: Mark Reidel <ports@mark.reidle.info>
# $FreeBSD$

PORTNAME=	mpc
PORTVERSION=	0.21
CATEGORIES=	audio ipv6
MASTER_SITES=	SF/musicpd/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@mark.reidel.info
COMMENT=	Command line client for the musicpd

LIB_DEPENDS=	mpdclient:${PORTSDIR}/audio/libmpdclient

OPTIONS_DEFINE=	EXAMPLES DOCS ICONV
OPTIONS_DEFAULT=	ICONV
ICONV_DESC=	Support for international characters

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

PORTDOCS=	AUTHORS README NEWS

PLIST_FILES=	bin/${PORTNAME} %%PORTEXAMPLES%%%%EXAMPLESDIR%%/${PORTNAME}-completion.bash

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLESDIR}
PLIST_DIRS=	%%EXAMPLESDIR%%
.endif

.ifndef(NO_INSTALL_MANPAGES)
MAN1=		${PORTNAME}.1
.endif

.if ${PORT_OPTIONS:MICONV}
USE_ICONV=	yes
.else
CONFIGURE_ARGS+=--disable-iconv
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lintl|-liconv|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}-completion.bash ${EXAMPLESDIR}
.endif
.ifndef(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/
.endif

.include <bsd.port.mk>
