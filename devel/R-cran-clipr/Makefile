# $FreeBSD$

PORTNAME=	clipr
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Read and Write from the System Clipboard

LICENSE=	GPLv3

USES=		cran:auto-plist

OPTIONS_DEFINE=	XCLIP XSEL
OPTIONS_DEFAULT=	XCLIP
XCLIP_DESC=	Use xclip for interacting with X11 clipboard
XSEL_DESC=	Use xsel for interacting with X11 clipboard

XCLIP_RUN_DEPENDS=	xclip:x11/xclip
XSEL_RUN_DEPENDS=	xsel:x11/xsel-conrad

.include <bsd.port.mk>
