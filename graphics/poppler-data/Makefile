# $FreeBSD$

PORTNAME=	poppler-data
PORTVERSION=	0.4.9
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://poppler.freedesktop.org/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Poppler encoding data

LICENSE=	MIT ADOBE GPLv2
LICENSE_COMB=	multi
LICENSE_NAME_ADOBE=	Adobe Systems Incorporated license
LICENSE_FILE_ADOBE=	${WRKSRC}/COPYING.adobe  # similar to BSD3CLAUSE
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING.gpl2
LICENSE_PERMS_ADOBE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		pathfix
PATHFIX_MAKEFILEIN=Makefile
MAKE_ARGS=	prefix=${PREFIX}
NO_ARCH=	yes

post-install:
# Share CMap files with Ghostscript.
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cmap
	${LN} ${STAGEDIR}${PREFIX}/share/poppler/cMap/*/* \
		${STAGEDIR}${PREFIX}/share/cmap

.include <bsd.port.mk>
