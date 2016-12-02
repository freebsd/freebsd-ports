# $FreeBSD$

PORTNAME=	libmpsse
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source library for SPI/I2C control via FTDI chips

LICENSE=	GPLv2

BUILD_DEPENDS=	swig2.0:devel/swig20
LIB_DEPENDS=	libftdi.so:devel/libftdi

BROKEN=		Unfetchable (google code has gone away)

USES=		gmake pkgconfig python:2
USE_AUTOTOOLS=	autoconf
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include -fPIC
LDFLAGS+=	-L${LOCALBASE}/lib -lftdi

CONFIGURE_WRKSRC=	${WRKSRC}/src
BUILD_WRKSRC=		${WRKSRC}/src
INSTALL_WRKSRC=		${WRKSRC}/src

MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ENV=  SWIG="swig2.0"

MAKE_ARGS=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

PORTDOCS=	INSTALL COPYING README README.* AN_135_MPSSE_Basics.pdf
PORTEXAMPLES=	*

PLIST_FILES= ${LOCALBASE}/lib/libmpsse.so ${LOCALBASE}/lib/libmpsse.a ${LOCALBASE}/include/mpsse.h \
				${PYTHON_SITELIBDIR}/mpsse.py ${PYTHON_SITELIBDIR}/pylibmpsse.py ${PYTHON_SITELIBDIR}/_pylibmpsse.so

pre-install:
	${MKDIR} ${STAGEDIR}/${LOCALBASE}/lib/

post-install:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name Makefile")
	${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
	(cd ${WRKSRC}/src/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "! -name Makefile")

	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_pylibmpsse.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmpsse.so

.include <bsd.port.mk>
