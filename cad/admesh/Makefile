# Created by: Pedro F. Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	admesh
DISTVERSIONPREFIX=	v
DISTVERSION=	0.98.4
CATEGORIES=	cad

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for processing STL triangulated solid meshes

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool
USE_GITHUB=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

PLIST_FILES=	bin/admesh \
		include/admesh/stl.h \
		lib/libadmesh.so \
		lib/libadmesh.so.1 \
		lib/libadmesh.so.1.0.0 \
		libdata/pkgconfig/libadmesh.pc \
		man/man1/admesh.1.gz

do-install-DOCS-on:
	@${RM} ${STAGEDIR}${DOCSDIR}/COPYING

.include <bsd.port.mk>
