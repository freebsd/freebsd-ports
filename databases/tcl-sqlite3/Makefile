PORTNAME=	sqlite3
DISTVERSION=	3.50.3
CATEGORIES=	databases tcl
MASTER_SITES=	SF/tcl/Tcl/9.0.2
PKGNAMEPREFIX=	tcl-
DISTNAME=	${TCL_PKG}

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	SQLite extension for Tcl using the Tcl Extension Architecture (TEA)
WWW=		https://www.sqlite.org/

LICENSE=	PD

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USES=		tcl:tea
TCL_PKG=	${PORTNAME:S/3//}${DISTVERSION}

.include <bsd.port.mk>
