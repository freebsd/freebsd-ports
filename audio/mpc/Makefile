# New ports collection makefile for:	mpc
# Date created:		Oct 02 2003
# Whom:			Mark Reidel <ports@mark.reidle.info>
#
# $FreeBSD$
#

PORTNAME=	mpc
PORTVERSION=	0.21
CATEGORIES=	audio ipv6
MASTER_SITES=	SF/musicpd/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@mark.reidel.info
COMMENT=	Command line client for the musicpd

LIB_DEPENDS=	mpdclient:${PORTSDIR}/audio/libmpdclient

OPTIONS=	ICONV "Support for international characters" on

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

PORTDOCS=	AUTHORS README NEWS

PLIST_FILES=	bin/${PORTNAME} %%PORTEXAMPLES%%%%EXAMPLESDIR%%/${PORTNAME}-completion.bash

.ifndef(NOPORTEXAMPLES)
PLIST_DIRS=	%%EXAMPLESDIR%%
.endif

.ifndef(NO_INSTALL_MANPAGES)
MAN1=		${PORTNAME}.1
.endif

.include <bsd.port.pre.mk>

.ifdef(WITHOUT_ICONV)
CONFIGURE_ARGS+=--disable-iconv
.else
USE_ICONV=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lintl|-liconv|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin/
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}-completion.bash ${EXAMPLESDIR}
.endif
.ifndef(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/
.endif

.include <bsd.port.post.mk>
