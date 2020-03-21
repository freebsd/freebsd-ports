# $FreeBSD$

PORTNAME=	pdfpc
DISTVERSION=	4.4.0
CATEGORIES=	graphics
DISTVERSIONPREFIX=	v
PORTREVISION=	1

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Keynote-like multi-monitor presentation viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libpoppler-glib.so:graphics/poppler-glib

USE_GITHUB=	yes

USES=		cmake gnome pkgconfig
USE_GNOME=	gtk30
USE_GSTREAMER1=	yes

CMAKE_ARGS=	-DMANDIR:STRING="man/"

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/pdfpcrc \
		${STAGEDIR}${PREFIX}/etc/pdfpcrc.sample

.include <bsd.port.mk>
