# Created by: Satoshi Asami <asami@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xli
PORTVERSION=	1.17.0
PORTREVISION=	14
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/x/${PORTNAME}
DISTNAME=	xli_${PORTVERSION}+${XLI_SNAPVER:C/-//g}.orig

MAINTAINER=	lichray@gmail.com
COMMENT=	Utilities to display images in X11

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

CONFLICTS_INSTALL=	xloadimage-*

USES=		imake desthack
USE_XORG=	xi
WRKSRC=		${WRKDIR}/xli-${XLI_SNAPVER}

XLI_SNAPVER=	2006-11-10

PLIST_FILES=	bin/xli \
		bin/xlito \
		man/man1/xli.1.gz \
		man/man1/xlito.1.gz

.include <bsd.port.mk>
