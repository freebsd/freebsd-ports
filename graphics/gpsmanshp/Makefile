# Created by: John Hay
# $FreeBSD$

PORTNAME=	gpsmanshp
PORTVERSION=	1.2.3
CATEGORIES=	graphics tcl geography
MASTER_SITES=	SF/${PORTNAME}/distr
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shapelib support for gpsman

LICENSE=	GPLv3+

LIB_DEPENDS=	libshp.so:devel/shapelib
RUN_DEPENDS=	gpsman:astro/gpsman

USES=		tar:tgz tcl
MAKE_ENV=	TCLVERSION="${TCL_VER}"
PLIST_SUB=	TCLVERSION="${TCL_VER}" PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS

post-install:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \
		. ${STAGEDIR}${DOCSDIR} \
		"! -name gpl-3_0.txt")

.include <bsd.port.mk>
