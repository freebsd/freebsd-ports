# New ports collection makefile for:	libggimisc
# Date created:				7 December 2004
# Whom:					antoine.brodin@laposte.net
#
# $FreeBSD$
#

PORTNAME=	libggimisc
PORTVERSION=	2.1.1
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.ggi-project.org/ftp/ggi/v2.1/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ggi
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	antoine.brodin@laposte.net
COMMENT=	A libggi extension providing support for hard to categorize features

LIB_DEPENDS=	ggi.2:${PORTSDIR}/graphics/libggi

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=	15

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"

MAN3=		ggiGetRayPos.3 \
		ggiSetSplitline.3 \
		ggiWaitRayPos.3
MAN7=		libggimisc.7

.include <bsd.port.pre.mk>

.if defined(WITH_SVGALIB) || exists(${LOCALBASE}/include/vga.h)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
PLIST_SUB+=	WITH_SVGALIB=""
.else
PLIST_SUB+=	WITH_SVGALIB="@comment "
.endif

post-install:
	@${CP} ${WRKSRC}/libggimisc.conf ${PREFIX}/etc/ggi/libggimisc.conf.dist

.include <bsd.port.post.mk>
