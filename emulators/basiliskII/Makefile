# New ports collection makefile for:	BasiliskII
# Date created:				17 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	basiliskII
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	http://gwenole.beauchesne.info/projects/basilisk2/files/
MASTER_SITE_SUBDIR=	basilisk
DISTNAME=	BasiliskII_src_01052006

MAINTAINER=	trasz@freebsd.org
COMMENT=	A free, portable, Open Source 68k Mac emulator

WRKSRC=		${WRKDIR}/BasiliskII-${PORTVERSION}/src/Unix

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	esound gtk20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-fbdev-dga --enable-fpe=uae ac_cv_have_33bit_addressing=no
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
