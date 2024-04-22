PORTNAME=	admesh
DISTVERSIONPREFIX=	v
DISTVERSION=	0.98.5
PORTREVISION=	1
CATEGORIES=	cad

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for processing STL triangulated solid meshes
WWW=		https://launchpad.net/admesh

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool
USE_GITHUB=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

PLIST_FILES=	bin/admesh \
		include/admesh/stl.h \
		lib/libadmesh.so \
		lib/libadmesh.so.1 \
		lib/libadmesh.so.1.0.0 \
		libdata/pkgconfig/libadmesh.pc \
		share/man/man1/admesh.1.gz

do-install-DOCS-on:
	@${RM} ${STAGEDIR}${DOCSDIR}/COPYING

.include <bsd.port.mk>
