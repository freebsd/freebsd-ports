# $FreeBSD$

PORTNAME=	tachyon
DISTVERSION=	0.98.9
CATEGORIES=	graphics science
MASTER_SITES=	http://jedi.ks.uiuc.edu/~johns/raytracer/files/${DISTVERSION}/

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Multiproccess ray tracing system

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../Copyright

WRKSRC=		${WRKDIR}/${PORTNAME}
WRKSRC_SUBDIR=	unix

PLIST_FILES=	bin/tachyon \
		lib/libtachyon.a

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../compile/${ARCH}/tachyon ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/../compile/${ARCH}/libtachyon.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.post.mk>
