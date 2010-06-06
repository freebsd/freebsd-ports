# New ports collection makefile for:	flac123
# Date created:		2004-05-14
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	flac123
PORTVERSION=	0.0.11
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF/flac-tools/${PORTNAME}/${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Command-line player for flac audio files

LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac \
		ao.4:${PORTSDIR}/audio/libao \
		popt.0:${PORTSDIR}/devel/popt

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	README.remote
PLIST_FILES=	bin/flac123

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
