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
PORTVERSION=	2.8.16
CATEGORIES=	databases
MASTER_SITES=	http://www.sqlite.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An SQL database engine in a C library w/ Tcl wrapper

DOCSDIR=	${PREFIX}/share/doc/sqlite2
EXAMPLESDIR=	${PREFIX}/share/examples/sqlite2
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}2

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
USE_GNOME=	pkgconfig
USE_LIBTOOL_VER=15
GNU_CONFIGURE=	YES
USE_REINPLACE=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-hints=freebsd.hints
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
ALL_TARGET=	all
#.if defined(WITH_TCL)
#ALL_TARGET+=	libtclsqlite.la
#.endif

INSTALLS_SHLIB=	YES

.include <bsd.port.pre.mk>

DOCFILES!=	${AWK} 'BEGIN {FS="/"}; /^%%PORTDOCS%%%%DOCSDIR%%/{print $$2}' pkg-plist

post-patch:
	@${REINPLACE_CMD} -e "s/tclsh \$$(TOP)/\$$(TCLSH) \$$(TOP)/g" \
			 -e "s|\./libtool|${LIBTOOL}|g" \
			 ${WRKSRC}/Makefile.in
	@${ECHO} "config_TARGET_TCL_INC=\"-I${PREFIX}/include/tcl${TCL_V}\"" >${WRKSRC}/freebsd.hints
	@${ECHO} "config_TARGET_TCL_LIBS=\"-L${PREFIX}/lib -ltcl${TCL_SHORT_V}\"" >>${WRKSRC}/freebsd.hints
	#@${ECHO} "config_TARGET_CFLAGS=\"-DTHREADSAFE=1 -pthread\"" >>${WRKSRC}/freebsd.hints

post-build:
	# Build the docs
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${GMAKE} ${MAKE_ARGS} doc
.endif

post-install:
.if defined(WITH_TCL)
	cd ${WRKSRC} && ${GMAKE} install-tcl
	${INSTALL_DATA} ${FILESDIR}/pkgIndex.tcl ${PREFIX}/lib/sqlite/
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/example.tcl ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
