# New ports collection makefile for:	BasiliskII
# Date created:				17 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	basiliskII
PORTVERSION=	0.9
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	basilisk
DISTNAME=	BasiliskII_src_31052001

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	lthread.2:${PORTSDIR}/devel/linuxthreads

WRKSRC=		${WRKDIR}/BasiliskII-${PORTVERSION}/src/Unix

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	esound gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-fbdev-dga
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"

CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include/pthread/linuxthreads

MAN1=		BasiliskII.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 400012
CFLAGS+=	-fpermissive
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
