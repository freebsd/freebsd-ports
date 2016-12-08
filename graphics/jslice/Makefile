# Created by: will
# $FreeBSD$

PORTNAME=	jslice
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.pldaniels.com/jslice/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphics tool to split up a JPEG image and provide HTML for the slices

USES=		jpeg

PLIST_FILES=	bin/jslice

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jslice ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
