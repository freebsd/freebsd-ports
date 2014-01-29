# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	xmms2-scrobbler
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.code-monkey.de/pub/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Last.fm submission client for XMMS2

LICENSE=	MIT

LIB_DEPENDS=	libxmmsclient.so:${PORTSDIR}/audio/xmms2 \
		libcurl.so:${PORTSDIR}/ftp/curl

USES=		gmake pkgconfig
LDFLAGS+=	${PTHREAD_LIBS}

PLIST_FILES=	bin/xmms2-scrobbler
PORTDOCS=	README

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
