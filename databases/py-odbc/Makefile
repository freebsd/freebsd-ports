# New ports collection makefile for:   pyodbc
# Date created:        April 15 2009
# Whom:                rkruus
#
# $FreeBSD$
#

# Like they say in the postgres-odbc Makefile (and I quote):
#
# This ODBC driver should work under either unixODBC or iODBC
# driver manager, when compliled against one. (Important: Do not try
# to have both installed -- they have overlapping files).

# It looks like most people are using unixODBC these days, rather than
# iODBC, so let's make unixODBC the default choice: to select iODBC,
# set WITH_IODBC, without setting WITH_UNIXODBC.  When the latter is
# set or when neither is set, we go with WITH_UNIXODBC.
#

PORTNAME=	pyodbc
PORTVERSION=	2.1.5
CATEGORIES=	databases python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=		pyodbc-${PORTVERSION}

MAINTAINER=	rob.kruus@gmail.com
COMMENT=	ODBC connections for python

USE_ZIP=	yes
USE_GMAKE=	yes
USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

# again, shamelessly copied from datebase/postgres-odbc
.if !defined(WITH_IODBC)
WITH_UNIXODBC=	yes
.endif

.if defined(WITH_UNIXODBC)
# I.e. even if WITH_IODBC is defined
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC
BUILD_DEPENDS+=	unixODBC>=2.2.14_1:${PORTSDIR}/databases/unixODBC
.else
LIB_DEPENDS+=	iodbc.3:${PORTSDIR}/databases/libiodbc
.endif

do-build:
	@(cd ${WRKSRC}; ${PYTHON_CMD} setup.py build)

do-install:
	@(cd ${WRKSRC}; ${PYTHON_CMD} setup.py install)

DOCSDIR=		${PREFIX}/share/doc/py-odbc

DOCS=			docs.html index.html license.html styles.css tutorial.html

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/web/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
