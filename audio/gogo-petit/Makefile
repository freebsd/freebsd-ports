# New ports collection makefile for:  GOGO-no-coda-petit
# Date created:        06 November, 2003
# Whom:                Evgueni V. Gavrilov <aquatique@rusunix.org>
#
# $FreeBSD$
#

PORTNAME=	gogo
PORTVERSION=	3.11
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://homepage1.nifty.com/herumi/soft/petit/ \
		ftp://rusunix.org/pub/FreeBSD/distfiles/
PKGNAMESUFFIX=	petit
DISTNAME=	petit311p1
EXTRACT_SUFX=	.tgz

MAINTAINER=	aquatique-ports@rambler.ru
COMMENT=	New variant of well-known GOGO-no-coda mp3 encoder

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

WRKSRC=		${WRKDIR}/petit

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV+=	LIBS="${PTHREAD_LIBS}"

ONLY_FOR_ARCHS=	i386
PLIST_FILES=	bin/gogo-petit

.include <bsd.port.mk>
