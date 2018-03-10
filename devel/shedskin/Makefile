# Created by: lightside <lightside@gmx.com>
# $FreeBSD$

PORTNAME=	shedskin
PORTVERSION=	0.9.4
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Experimental (restricted) Python-to-C++ compiler

LICENSE=	GPLv3 MIT BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/lib/libgc.so:devel/boehm-gc \
		${LOCALBASE}/lib/libpcre.so:devel/pcre

USE_GITHUB=	yes

USES=		python:2.7
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e '/^CC/s|g++|$$(CXX)| ; \
		/^CCFLAGS/s|-O2 -march=native|$$(CXXFLAGS) -I${LOCALBASE}/include| ; \
		/^LFLAGS/s|=|&-L${LOCALBASE}/lib |' \
			${WRKSRC}/shedskin/FLAGS

do-install-EXAMPLES-on:
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} "${PORTEXAMPLES}" \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
