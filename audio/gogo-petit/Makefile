# New ports collection makefile for:  GOGO-no-coda-petit
# Date created:        06 November, 2003
# Whom:                Evgueni V. Gavrilov <aquatique@rusunix.org>
#
# $FreeBSD$
#

PORTNAME=	gogo
PORTVERSION=	3.13
CATEGORIES=	audio
MASTER_SITES=	http://homepage2.nifty.com/kei-i/petit/ \
		ftp://rusunix.org/pub/FreeBSD/distfiles/
PKGNAMESUFFIX=	petit
DISTNAME=	petit313
EXTRACT_SUFX=	.tgz

MAINTAINER=	aquatique-ports@rambler.ru
COMMENT=	New variant of well-known GOGO-no-coda mp3 encoder

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

WRKSRC=		${WRKDIR}/${DISTNAME}/FreeBSD

USE_REINPLACE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}

ONLY_FOR_ARCHS=	i386
PLIST_FILES=	bin/gogo-petit

post-patch:
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}| ; \
	s|/usr/local/bin|${PREFIX}/bin|g' ${WRKSRC}/Makefile || @${ECHO} yo

.include <bsd.port.mk>
