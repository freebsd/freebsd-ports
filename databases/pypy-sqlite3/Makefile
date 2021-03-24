# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sqlite3
CATEGORIES=	databases python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Standard PyPy binding to the SQLite3 library

DEPRECATED=	Uses EOL Python 2.7 via lang/pypy
EXPIRATION_DATE=2021-06-23

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

CFFI_NAME=	_ffi

.include "${.CURDIR}/../../lang/pypy/bsd.pypy.cffi.mk"
.include <bsd.port.mk>
