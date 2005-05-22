# ex:ts=8
# New ports collection makefile for:	sqlite
# Date created:			Feb 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

# By default, this port depends on TCL for building docs. If you want to build
# without TCL (and thus get no docs), define NOPORTDOCS.
# If you want to build the TCL wrapper, you have to define SQLITE_WITH_TCL84.

PORTNAME=	sqlite
PORTVERSION=	3.2.1
CATEGORIES=	databases
MASTER_SITES=	http://www.sqlite.org/

MAINTAINER=	green@FreeBSD.org
COMMENT=	An SQL database engine in a C library w/ Tcl wrapper (beta)

USE_GMAKE=		YES
USE_GNOME=		pkgconfig
USE_LIBTOOL_VER=	15
HAS_CONFIGURE=		YES
USE_REINPLACE=		YES
INSTALLS_SHLIB=		YES

DOCSDIR=	${PREFIX}/share/doc/sqlite3
EXAMPLESDIR=	${PREFIX}/share/examples/sqlite3
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}3

# Defaults, for building the docs:
TCL_V?=		8.4

OPTIONS=	TCL84	"TCL wrapper for SQLITE" off

.include <bsd.port.pre.mk>

.if defined(WITH_TCL84)
CATEGORIES+=	lang
WITH_TCL=	YES
.endif

.if defined(WITH_TCL)
ALL_TARGET+=	libtclsqlite.la
PLIST_SUB+=	WITH_TCL=""
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl${TCL_V}
.else
PLIST_SUB+=	WITH_TCL="@comment "
CONFIGURE_ARGS=	--disable-tcl
.endif

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	tclsh${TCL_V}:${PORTSDIR}/lang/tcl${TCL_V:S/.//}
MAKE_ARGS+=	TCLSH=tclsh${TCL_V}
MAKE_ENV+=	TCL_VER=${TCL_V}
.endif

CONFIGURE_ARGS+=	--prefix=${PREFIX} --with-hints=freebsd.hints
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
ALL_TARGET=		all

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/tclsh \$$(TOP)/\$$(TCLSH) \$$(TOP)/g" \
		-e "s|\./libtool|${LIBTOOL}|g" ${WRKSRC}/Makefile.in
	@${ECHO} "config_TARGET_TCL_INC=\"-I${PREFIX}/include/tcl${TCL_V}\"" >${WRKSRC}/freebsd.hints
	@${ECHO} "config_TARGET_TCL_LIBS=\"-L${PREFIX}/lib -ltcl${TCL_V:S/.//}\"" >>${WRKSRC}/freebsd.hints
#	@${ECHO} "config_TARGET_CFLAGS=\"-DTHREADSAFE=1 -pthread\"" >>${WRKSRC}/freebsd.hints

post-build:
	# Build the docs
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} && ${GMAKE} ${MAKE_ARGS} doc)
.endif

post-install:
.if defined(WITH_TCL)
	@${MKDIR} ${PREFIX}/lib/sqlite
	@(cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_DATA} \
	    libtclsqlite3.la ${PREFIX}/lib/sqlite/)
	@${INSTALL_DATA} ${FILESDIR}/pkgIndex.tcl ${PREFIX}/lib/sqlite/
	@${INSTALL_PROGRAM} ${WRKSRC}/.libs/tclsqlite3 ${PREFIX}/bin
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${FILESDIR}/example.tcl ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
