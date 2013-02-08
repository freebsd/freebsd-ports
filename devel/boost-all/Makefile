# Created by: Alexander Churanov <churanov.port.maintainer@gmail.com>
# $FreeBSD$

PORTNAME=	boost-all

MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

COMMENT?=	The "meta-port" for boost libraries

OPTIONS_DEFINE=	JAM LIBRARIES PYTHON DOCS
OPTIONS_DEFAULT=	JAM LIBRARIES
JAM_DESC=	Boost.Jam - Build tool from the boost.org
LIBRARIES_DESC=	Free portable C++ libraries
PYTHON_DESC=	Boost.Python - interfacing Python and C++

NO_BUILD=	yes

.include <bsd.port.pre.mk>
.include "common.mk"

.if ${PORT_OPTIONS:MLIBRARIES}
RUN_DEPENDS+=	${LOCALBASE}/lib/libboost_thread.so:${PORTSDIR}/devel/boost-libs
.endif

.if ${PORT_OPTIONS:MJAM}
RUN_DEPENDS+=	${LOCALBASE}/bin/bjam:${PORTSDIR}/devel/boost-jam
.endif

.if ${PORT_OPTIONS:MPYTHON}
RUN_DEPENDS+=	${LOCALBASE}/lib/libboost_python.so:${PORTSDIR}/devel/boost-python-libs
.endif

.if ${PORT_OPTIONS:MDOCS}
RUN_DEPENDS+=	${LOCALBASE}/share/doc/boost/doc/html/index.html:${PORTSDIR}/devel/boost-docs
.endif

do-install:
	${DO_NADA}

.include <bsd.port.post.mk>
