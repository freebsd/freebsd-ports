# $FreeBSD$

PORTNAME=	libmpsse
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source library for SPI/I2C control via FTDI chips

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	swig2.0:devel/swig20
LIB_DEPENDS=	libftdi.so:devel/libftdi

USES=		autoreconf localbase:ldflags pkgconfig python:2
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	devttys0
GH_TAGNAME=	f1a6744b220d

WRKSRC_SUBDIR=	src

CONFIGURE_ENV=  SWIG="swig2.0"

PORTDOCS=	INSTALL LICENSE README README.* AN_135_MPSSE_Basics.pdf
PORTEXAMPLES=	*

PLIST_FILES=	lib/libmpsse.so lib/libmpsse.a include/mpsse.h \
		${PYTHONPREFIX_SITELIBDIR}/_pylibmpsse.so \
		${PYTHONPREFIX_SITELIBDIR}/mpsse.py \
		${PYTHONPREFIX_SITELIBDIR}/pylibmpsse.py

post-install:
	(cd ${WRKSRC}/../docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name Makefile")
	(cd ${WRKSRC}/../src/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "! -name Makefile")
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_pylibmpsse.so 
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmpsse.so

.include <bsd.port.mk>
