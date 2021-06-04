# Created by: Wen Heping <wenheping@gmail.com>

PORTNAME=	swe
PORTVERSION=	2.10.1
CATEGORIES=	astro devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	High Precision Ephemeris Developed By Astrodienst

LICENSE=	AGPLv3

USES=		gmake
USE_GITHUB=	nodefault

GH_ACCOUNT=	aloistr:src,doc
GH_PROJECT=	swisseph:src swisseph_doc:doc
GH_TAGNAME=	v${PORTVERSION}:src v${PORTVERSION:S/./,/g}:doc

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/swisseph-${PORTVERSION}
ALL_TARGET=	#
MAKEFILE=	makefile

post-patch:
	@${REINPLACE_CMD} 's|-ldl||' ${WRKSRC}/makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/libswe.a ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/include/swe
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/swe

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/swisseph_doc-${PORTVERSION:S/./-/g}/* ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
