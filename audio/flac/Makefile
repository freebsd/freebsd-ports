# ex:ts=8
# New ports collection makefile for:	flac
# Date created:		Mar 18, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flac
PORTVERSION=	0.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ijliao@FreeBSD.org

.if defined(WITH_XMMS)
BUILD_DEPENDS+=	xmms-config:${PORTSDIR}/audio/xmms
LIB_DEPENDS+=	xmms.1:${PORTSDIR}/audio/xmms
.endif

ONLY_FOR_ARCHS=	i386

USE_LIBTOOL=	yes
USE_AUTOMAKE=	yes
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes

INSTALLS_SHLIB=	yes

post-install:
.if !defined(NO_PORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/flac
	${MKDIR} ${PREFIX}/share/doc/flac/images
	${CP} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/flac
.for file in logo.jpg 1x1.gif
	${CP} ${WRKSRC}/doc/images/${file} ${PREFIX}/share/doc/flac/images
.endfor
.endif

.include <bsd.port.mk>
