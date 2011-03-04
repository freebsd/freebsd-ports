# New ports collection makefile for:	qiv
# Date created:		25 December 1998
# Whom:			Bill Fumerola <billf@chc-chimes.com>
#
# $Carpetsmoker: ports/graphics/qiv/Makefile,v 1.2 2008/01/26 15:24:30 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	qiv
PORTVERSION=	2.2.3
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://spiegl.de/qiv/download/ \
		http://www.predatorlabs.net/dl/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Small, fast GDK/Imlib2 image viewer

LIB_DEPENDS=	Imlib2.5:${PORTSDIR}/graphics/imlib2 \
		exif.12:${PORTSDIR}/graphics/libexif

USE_GMAKE=	yes
USE_GNOME=	gtk20

MAKE_JOBS_SAFE=	yes

OPTIONS=	XINERAMA "use multiple monitors" off

MAN1=		qiv.1
PLIST_FILES=	bin/qiv
USE_XORG+=	x11

.include <bsd.port.pre.mk>

pre-configure:
.if ! defined(WITH_XINERAMA)
	@${REINPLACE_CMD} 's|GTD.*=|#|' ${WRKSRC}/Makefile
.else
USE_XORG+=	xinerama
.endif

do-configure:
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|; \
		s|gcc|${CC}|; \
		s|-O2|${CFLAGS}|; \
		s|libs-gdk`|libs-gdk` ${LDFLAGS}|;' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qiv ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/qiv.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.post.mk>
