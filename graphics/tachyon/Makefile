PORTNAME=	tachyon
DISTVERSION=	0.98.9
PORTREVISION=	1
CATEGORIES=	graphics science
MASTER_SITES=	http://jedi.ks.uiuc.edu/~johns/raytracer/files/${DISTVERSION}/

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Multiproccess ray tracing system
WWW=		http://jedi.ks.uiuc.edu/~johns/raytracer/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright

ALL_TARGET=	bsd
BUILD_WRKSRC=	${WRKSRC}/unix
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/tachyon \
		lib/libtachyon.a

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/compile/bsd/tachyon ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/compile/bsd/libtachyon.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.post.mk>
