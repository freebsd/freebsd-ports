# $FreeBSD$

PORTNAME=	libmpsse
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source library for SPI/I2C control via FTDI chips

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../docs/LICENSE

BUILD_DEPENDS=	swig3.0:devel/swig30
LIB_DEPENDS=	libftdi.so:devel/libftdi

USE_GITHUB=	yes
GH_ACCOUNT=	devttys0
GH_TAGNAME=	f1a6744b220d

USES=		autoreconf localbase:ldflags pkgconfig python:2.7
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SWIG="swig3.0"
USE_LDCONFIG=	yes

WRKSRC_SUBDIR=	src

PORTDOCS=	README README.* AN_135_MPSSE_Basics.pdf
PORTEXAMPLES=	*

PLIST_FILES=	lib/libmpsse.so lib/libmpsse.a include/mpsse.h \
		${PYTHONPREFIX_SITELIBDIR}/_pylibmpsse.so \
		${PYTHONPREFIX_SITELIBDIR}/mpsse.py \
		${PYTHONPREFIX_SITELIBDIR}/pylibmpsse.py

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_pylibmpsse.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmpsse.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/../docs && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@(cd ${WRKSRC}/../src/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "! -name Makefile")

.include <bsd.port.mk>
