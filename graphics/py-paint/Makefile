# Created by: Hye-Shik Chang <perky@python.or.kr>
# $FreeBSD$

PORTNAME=	paint
PORTVERSION=	0.3
PORTREVISION=	6
CATEGORIES=	graphics python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/py${PORTNAME}%20${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pypaint-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and flexible painting adaptor to libart for Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

LIB_DEPENDS=	libpng.so:graphics/png \
		libttf.so:print/freetype

OPTIONS_DEFINE=	EXAMPLES

USES=		python
USE_PYTHON=	distutils autoplist
USE_GNOME=	libartlgpl2
NO_WRKSUBDIR=	yes
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libart-2.0 \
		-I${LOCALBASE}/include/freetype1
LDFLAGS+=	-L${LOCALBASE}/lib

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} -e "s,art_lgpl,art_lgpl_2," ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/paint.so
post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/test* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
