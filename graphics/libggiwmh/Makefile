# New ports collection makefile for:	libggiwmh
# Date created:				7 December 2004
# Whom:					antoine.brodin@laposte.net
#
# $FreeBSD$
#

PORTNAME=	libggiwmh
PORTVERSION=	0.2.0
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.ggi-project.org/ftp/ggi/v2.1/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ggi
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	antoine.brodin@laposte.net
COMMENT=	A libggi extension, wmh stands for Window Manager Hints

LIB_DEPENDS=	ggi.2:${PORTSDIR}/graphics/libggi

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

MAN3=		ggiWmhIconify.3 \
		ggiWmhInit.3 \
		ggiWmhMove.3 \
		ggiWmhSetTitle.3 \
		ggiWmhZOrder.3
MAN7=		libggiwmh.7
MLINKS=		ggiWmhIconify.3 ggiWmhMoveIcon.3 \
		- ggiWmhSetIconTitle.3 \
		ggiWmhInit.3 ggiWmhAttach.3 \
		- ggiWmhDetach.3 - ggiWmhExit.3 \
		ggiWmhMove.3 ggiWmhAllowResize.3 \
		- ggiWmhGetPos.3 - ggiWmhGetSize.3 \
		- ggiWmhResize.3

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
PLIST_SUB+=	XWMH=""
.else
CONFIGURE_ARGS+=--disable-x
PLIST_SUB+=	XWMH="@comment "
.endif

post-install:
	@${CP} ${WRKSRC}/libggiwmh.conf ${PREFIX}/etc/ggi/libggiwmh.conf.dist

.include <bsd.port.post.mk>
