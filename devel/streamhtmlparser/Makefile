# Created by: HU Dong <itechbear@gmail.com>
# $FreeBSD$

PORTNAME=	streamhtmlparser
PORTVERSION=	0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	itechbear@gmail.com
COMMENT=	C/C++/Python streaming HTML parser library from Google

LICENSE=	BSD2CLAUSE

USES=		gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--enable-shared

OPTIONS_DEFINE=	DOCS STATIC PYBINDINGS
PYBINDINGS_DESC=Install Python bindings
STATIC_DESC=	Install static library
OPTIONS_DEFAULT=STATIC
OPTIONS_SUB=	yes

PYBINDINGS_USE=	python=yes
PYBINDINGS_CONFIGURE_ENABLE=	python
PYBINDINGS_CFLAGS=	-I${PYTHON_INCLUDEDIR}

STATIC_CONFIGURE_ENABLE=	static

post-patch:
	@${REINPLACE_CMD} -e 's|^docdir.*|docdir = ${DOCSDIR}|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
