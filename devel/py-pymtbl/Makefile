# $FreeBSD$

PORTNAME=	pymtbl
PORTVERSION=	0.4.1
#PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Python wrapper for devel/mtbl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

LIB_DEPENDS=	libmtbl.so:devel/mtbl

USES=		pkgconfig python:-3.6 shebangfix uniquefiles:dirs
USE_PYTHON=	autoplist distutils

SHEBANG_FILES=	examples/*.py examples/*/*.py

PORTEXAMPLES=	*

CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PYTHON_SITELIBDIR}/mtbl.so
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
