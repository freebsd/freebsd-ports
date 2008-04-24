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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	New variant of well-known GOGO-no-coda mp3 encoder

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

WRKSRC=		${WRKDIR}/${DISTNAME}/FreeBSD

AS =		nasm
AFLAGS =	-f elf -Ox
ALL_TARGET=	test
MAKE_ENV+=	AS="${AS}" \
		AFLAGS="${AFLAGS}" \
		LDFLAGS="${LDFLAGS}"

ONLY_FOR_ARCHS=	i386
PLIST_FILES=	bin/gogo-petit

OPTIONS=	THREADS	"build a multithreaded encoder for SMP" Off

.include <bsd.port.pre.mk>

.ifdef(WITH_THREADS)
LDFLAGS+=	${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS}
MAKEFILE=	${FILESDIR}/Makefile.rfork
.else
MAKEFILE=	${FILESDIR}/Makefile.unthreaded
.endif

.include <bsd.port.post.mk>
