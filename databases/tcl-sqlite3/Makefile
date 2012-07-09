# New ports collection makefile for:	sqlite3-tea
# Date created:		2011-03-23
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite3
PORTVERSION=	3.7.13
CATEGORIES=	databases tcl
MASTER_SITES=	http://www.sqlite.org/ http://www2.sqlite.org/ http://www3.sqlite.org/
PKGNAMEPREFIX=	tcl-
DISTNAME=	sqlite-autoconf-3071300

MAINTAINER=	pavelivolkov@googlemail.com
COMMENT=	SQLite extension for Tcl using the Tcl Extension Architecture (TEA)

LICENSE=	public
LICENSE_NAME=	Public Domain
LICENSE_TEXT=	Description of the license can be obtained from the following URL: http://www.sqlite.org/copyright.html
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3

WRKSRC=		${WRKDIR}/${DISTNAME}/tea

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_TCL=	yes

CFLAGS+=	`pkg-config --cflags --libs sqlite3`
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR} --with-system-sqlite

PLIST_DIRS+=		lib/sqlite3
PLIST_FILES+=		lib/sqlite3/libsqlite.so.1 lib/sqlite3/pkgIndex.tcl
PORTEXAMPLES=		*

SUB_FILES=	example.tcl
SUB_LIST=	"TCLSH=${TCLSH}"

MANN=	sqlite3.n

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} 's,\(^PKG_DIR.*\)$$(PACKAGE_VERSION),\13,g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/${SUB_FILES} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
