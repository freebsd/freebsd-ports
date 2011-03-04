# New ports collection makefile for:	xmms2-scrobbler
# Date created:				06 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$

PORTNAME=	xmms2-scrobbler
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.code-monkey.de/pub/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A last.fm submission client for XMMS2

LICENSE=	MIT

LIB_DEPENDS=	xmmsclient.6:${PORTSDIR}/audio/xmms2 \
		curl.6:${PORTSDIR}/ftp/curl

USE_GMAKE=	yes
MAKE_ENV=	LDFLAGS="${PTHREAD_LIBS}"

PLIST_FILES=	bin/xmms2-scrobbler
PORTDOCS=	README

SUB_FILES=	pkg-message

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}; \
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
