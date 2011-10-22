# New ports collection makefile for:	boost-all
# Date created:				March 21 2009
# Whom:					Alexander Churanov <churanov.port.maintainer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	boost-all

MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

COMMENT?=	The "meta-port" for boost libraries

OPTIONS=	JAM "Boost.Jam - Build tool from the boost.org" on \
		LIBRARIES "Free portable C++ libraries" on \
		PYTHON "Boost.Python - interfacing Python and C++" off \
		DOCS "Documentation & examples" on

NO_BUILD=	yes

.include <bsd.port.pre.mk>
.include "common.mk"

.if !defined(WITHOUT_LIBRARIES)
RUN_DEPENDS+=	${LOCALBASE}/lib/libboost_thread.so:${PORTSDIR}/devel/boost-libs
.endif

.if !defined(WITHOUT_JAM)
RUN_DEPENDS+=	${LOCALBASE}/bin/bjam:${PORTSDIR}/devel/boost-jam
.endif

.if !defined(WITHOUT_PYTHON)
RUN_DEPENDS+=	${LOCALBASE}/lib/libboost_python.so:${PORTSDIR}/devel/boost-python-libs
.endif

.if !defined(WITHOUT_DOCS)
RUN_DEPENDS+=	${LOCALBASE}/share/doc/boost/doc/html/index.html:${PORTSDIR}/devel/boost-docs
.endif

do-install:
	${DO_NADA}

.include <bsd.port.post.mk>
