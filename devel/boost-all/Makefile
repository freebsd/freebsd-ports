PORTNAME=	boost-all

USES=		metaport

COMMENT?=	The "meta-port" for boost libraries
WWW=		https://www.boost.org/

OPTIONS_DEFINE=	JAM LIBRARIES PYTHON MPI DOCS
OPTIONS_DEFAULT=	JAM LIBRARIES
JAM_DESC=	Boost.Jam - Build tool from the boost.org
LIBRARIES_DESC=	Free portable C++ libraries
PYTHON_DESC=	Boost.Python - interfacing Python and C++
MPI_DESC=	Boost.MPI + Python bindings

.include "common.mk"

LIBRARIES_RUN_DEPENDS=	${LOCALBASE}/lib/libboost_thread.so:devel/boost-libs
JAM_RUN_DEPENDS=	${LOCALBASE}/bin/bjam:devel/boost-jam
PYTHON_RUN_DEPENDS=	${LOCALBASE}/lib/${PY_BOOST}
PYTHON_USES=		python:env
MPI_IMPLIES=		PYTHON
MPI_RUN_DEPENDS=	${LOCALBASE}/lib/libboost_mpi.so:devel/boost-mpi-libs@${PY_FLAVOR}
DOCS_RUN_DEPENDS=	${LOCALBASE}/share/doc/boost/doc/html/index.html:devel/boost-docs

.include <bsd.port.mk>
