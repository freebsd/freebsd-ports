# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	qiv
PORTVERSION=	2.2.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://spiegl.de/qiv/download/ \
		http://www.predatorlabs.net/dl/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, fast GDK/Imlib2 image viewer

LICENSE=	GPLv2

LIB_DEPENDS=	libImlib2.so:${PORTSDIR}/graphics/imlib2

USES=		gmake pkgconfig
USE_GNOME=	gtk20

OPTIONS_DEFINE=	XINERAMA

MAN1=		qiv.1
PLIST_FILES=	bin/qiv
USE_XORG+=	x11

.include <bsd.port.options.mk>

post-patch-script:
.if ${PORT_OPTIONS:MXINERAMA}
USE_XORG+=	xinerama
.else
	@${REINPLACE_CMD} 's|GTD.*=|#|' ${WRKSRC}/Makefile
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

.include <bsd.port.mk>
