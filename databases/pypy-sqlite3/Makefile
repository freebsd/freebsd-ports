# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sqlite3
PORTVERSION=	${PYTHON_PORTVERSION}
CATEGORIES=	databases python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Standard PyPy binding to the SQLite3 library

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

CFFI_NAME=	_ffi

.include "${.CURDIR}/../../lang/pypy/bsd.pypy.cffi.mk"
.include <bsd.port.mk>
