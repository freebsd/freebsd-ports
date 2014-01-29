# Created by: ijliao
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	1.4
PORTREVISION=	4
CATEGORIES=	ftp
MASTER_SITES=	SF/rexx${PORTNAME}/rexx${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	rexx-
DISTNAME=	RexxCURL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	External function package providing an interface to the cURL package

OPTIONS_DEFINE=	DOCS

BUILD_DEPENDS=	rexx:${PORTSDIR}/lang/rexx-regina
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	rexx:${PORTSDIR}/lang/rexx-regina

USES=		gmake
GNU_CONFIGURE=	yes
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
CONFIGURE_ARGS=	--with-rexx=regina
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/rexx${PORTNAME}
DATADIR=	${PREFIX}/share/rexx${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s| -lc | |g" -e "/\$(sharedir)\/images/d" \
		-e "/index.html/d" -e "/rxcurl64.png/d" ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/index.html ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/images/rxcurl64.png ${STAGEDIR}${DOCSDIR}/images

.include <bsd.port.mk>
