# ex:ts=8
# New ports collection makefile for:	sqlite
# Date created:			Feb 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

# By default, this port depends on TCL for building docs. If you want to build
# without TCL (and thus get no docs), define NOPORTDOCS.
# If you want to build the TCL wrapper, you have to choose between
# SQLITE_WITH_TCL83 and SQLITE_WITH_TCL84.

PORTNAME=	sqlite
PORTVERSION=	3.0.8
CATEGORIES=	databases
MASTER_SITES=	http://www.sqlite.org/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	green@FreeBSD.org
COMMENT=	An SQL database engine in a C library w/ Tcl wrapper (beta)

DOCSDIR=	${PREFIX}/share/doc/sqlite3
EXAMPLESDIR=	${PREFIX}/share/examples/sqlite3
NO_LATEST_LINK=	yes

# Defaults, for building the docs:
TCL_V=		8.4
TCL_SHORT_V=	84

.if defined(SQLITE_WITH_TCL83)
CATEGORIES+=	tcl83
TCL_V=		8.3
TCL_SHORT_V=	83
WITH_TCL=	YES
.endif

.if defined(SQLITE_WITH_TCL84)
CATEGORIES+=	tcl84
TCL_V=		8.4
TCL_SHORT_V=	84
WITH_TCL=	YES
.endif

.if defined(WITH_TCL)
LIB_DEPENDS+=	tcl${TCL_SHORT_V}:${PORTSDIR}/lang/tcl${TCL_SHORT_V}
PLIST_SUB+=	WITH_TCL=""
.else
PLIST_SUB+=	WITH_TCL="@comment "
.endif

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	tclsh${TCL_V}:${PORTSDIR}/lang/tcl${TCL_SHORT_V}
MAKE_ARGS+=	TCLSH=tclsh${TCL_V}
MAKE_ENV+=	TCL_VER=${TCL_V}
.endif

USE_GMAKE=	YES
USE_LIBTOOL_VER=	13
GNU_CONFIGURE=	YES
USE_REINPLACE=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-hints=freebsd.hints
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
ALL_TARGET=	all
.if defined(WITH_TCL)
ALL_TARGET+=	libtclsqlite3.la tclsqlite3
.endif

INSTALLS_SHLIB=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e "s/tclsh \$$(TOP)/\$$(TCLSH) \$$(TOP)/g" \
			 -e "s|%%LIBTOOL%%|${LIBTOOL}|g" \
			 ${WRKSRC}/Makefile.in
	${ECHO} "config_TARGET_TCL_INC=\"-I${PREFIX}/include/tcl${TCL_V}\"" >${WRKSRC}/freebsd.hints
	${ECHO} "config_TARGET_TCL_LIBS=\"-L${PREFIX}/lib -ltcl${TCL_SHORT_V}\"" >>${WRKSRC}/freebsd.hints
	#${ECHO} "config_TARGET_CFLAGS=\"-DTHREADSAFE=1 -pthread\"" >>${WRKSRC}/freebsd.hints

post-build:
	# Build the docs
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${GMAKE} ${MAKE_ARGS} doc
.endif

DOCFILES=	${AWK} 'BEGIN {FS="/"}; /^%%PORTDOCS%%%%DOCSDIR%%/{print $$2 }' < pkg-plist

post-install:
.if defined(WITH_TCL)
	@${MKDIR} ${PREFIX}/lib/sqlite
	cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_DATA} \
	    libtclsqlite3.la ${PREFIX}/lib/sqlite/
	@${RM} ${PREFIX}/lib/sqlite/libtclsqlite3.la
	${INSTALL_DATA} ${FILESDIR}/pkgIndex.tcl ${PREFIX}/lib/sqlite/
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/tclsqlite3 ${PREFIX}/bin
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	for f in `${DOCFILES}`; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$${f} ${DOCSDIR}; \
	done
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${FILESDIR}/example.tcl ${EXAMPLESDIR}

.endif

.include <bsd.port.mk>
