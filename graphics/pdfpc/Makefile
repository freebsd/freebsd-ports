# $FreeBSD$

PORTNAME=	pdfpc
PORTVERSION=	4.0.2
CATEGORIES=	graphics
DISTVERSIONPREFIX=	v

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Keynote-like multi-monitor presentation viewer

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libgee-0.8.so:${PORTSDIR}/devel/libgee \
		libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib

USE_GITHUB=	yes

USES=		cmake gnome pkgconfig pathfix
USE_GNOME=	gtk30
USE_GSTREAMER1=	yes

CMAKE_ARGS=	-DMANDIR:STRING="man/man1"

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/pdfpcrc \
		${STAGEDIR}${PREFIX}/etc/pdfpcrc.sample

.include <bsd.port.mk>
