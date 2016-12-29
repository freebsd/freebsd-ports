# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qross
PORTVERSION=	0.3.1
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Qt-only fork of Kross, the KDE scripting framework

LICENSE=	LGPL20+

USES=		cmake
USE_LDCONFIG=	yes
USE_QT4=	designer gui network xml qmake_build uic_build moc_build \
		rcc_build script testlib
USE_GITHUB=	yes
GH_ACCOUNT=	0xd34df00d
GH_PROJECT=	Qross

WRKSRC_SUBDIR=	src

OPTIONS_DEFINE=	PYTHON
OPTIONS_SUB=	yes
PYTHON_DESC=		Python bindings
PYTHON_CMAKE_ON=	-DENABLE_PYTHON:BOOL=true
PYTHON_CMAKE_OFF=	-DENABLE_PYTHON:BOOL=false
PYTHON_BUILD_DEPENDS=	sip:devel/py-sip
OPTIONS_DEFAULT=PYTHON

post-extract:
	@${CP} ${FILESDIR}/CMakeLists.txt ${WRKSRC}

post-install:
.for lib in libqrossui libqrosscore qrossqts
	@${LN} -s ${lib}.so.0.1 ${STAGEDIR}${PREFIX}/lib/${lib}.so.1
.endfor

.include <bsd.port.mk>
