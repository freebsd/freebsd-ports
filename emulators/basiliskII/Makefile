# New ports collection makefile for:	BasiliskII
# Date created:				17 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	basiliskII
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://wwwthep.physik.uni-mainz.de/~cbauer/
MASTER_SITE_SUBDIR=	basilisk
DISTNAME=	BasiliskII_src_15012002

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free, portable, Open Source 68k Mac emulator

WRKSRC=		${WRKDIR}/BasiliskII-${PORTVERSION}/src/Unix

USE_X_PREFIX=	yes
USE_GNOME=	esound gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-fbdev-dga --enable-fpe=uae
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		BasiliskII.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 400012
CFLAGS+=	-fpermissive
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
