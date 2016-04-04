# $FreeBSD$

PORTNAME=	pymtbl
PORTVERSION=	0.4.0
CATEGORIES=	devel python
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Python wrapper for devel/mtbl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libmtbl.so:devel/mtbl

USE_PYTHON=	autoplist distutils
USES=		pkgconfig python shebangfix uniquefiles:dirs

SHEBANG_FILES=	examples/*.py examples/*/*.py

PORTEXAMPLES=	*

CPPFLAGS+=	-I${LOCALBASE}/include

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PYTHON_SITELIBDIR}/mtbl.so
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
