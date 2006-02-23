# ex:ts=8
# New ports collection makefile for:	sqlite
# Date created:			Feb 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite
PORTVERSION=	2.8.17
CATEGORIES=	databases
MASTER_SITES=	http://www.sqlite.org/

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	An SQL database engine in a C library w/ Tcl wrapper

USE_GMAKE=	YES
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	YES

CONFIGURE_ARGS=		--prefix=${PREFIX} --with-hints=freebsd.hints
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

DOCSDIR=	${PREFIX}/share/doc/sqlite2
EXAMPLESDIR=	${PREFIX}/share/examples/sqlite2

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}2

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude CVS

OPTIONS=	TCL84	"Enable TCL wrapper (tcl 8.4)"	off \
		TCL83	"Enable TCL wrapper (tcl 8.3)"	off \
		THREADS	"Compile with threads support"	off \
		DOCS	"Building docs (depends on TCL)"	on

# Defaults, for building the docs:
TCL_VERSION=	8.4

.include <bsd.port.pre.mk>

# Deprecated options
.if defined(SQLITE_WITH_TCL83)
WITH_TCL83=	yes
.endif
.if defined(SQLITE_WITH_TCL84)
WITH_TCL84=	yes
.endif

.if defined(WITH_TCL83)
.if defined(WITH_TCL84)
BROKEN=		please, select only one TCL wrapper
.endif
CATEGORIES+=	tcl83
TCL_VERSION=	8.3
WITH_TCL=	YES
.endif

.if defined(WITH_TCL84)
.if defined(WITH_TCL83)
BROKEN=		please, select only one TCL wrapper
.endif
CATEGORIES+=	tcl84
TCL_VERSION=	8.4
WITH_TCL=	YES
.endif

.if defined(WITH_TCL)
LIB_DEPENDS+=	tcl${TCL_VERSION:S/.//}:${PORTSDIR}/lang/tcl${TCL_VERSION:S/.//}
PLIST_SUB+=	WITH_TCL=""
.else
PLIST_SUB+=	WITH_TCL="@comment "
.endif

.if !defined(NOPORTDOCS) && !defined(WITHOUT_DOCS)
PORTDOCS=	*
BUILD_DEPENDS+=	tclsh${TCL_VERSION}:${PORTSDIR}/lang/tcl${TCL_VERSION:S/.//}
MAKE_ARGS+=	TCLSH=tclsh${TCL_VERSION}
MAKE_ENV+=	TCL_VER=${TCL_VERSION}
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/tclsh \$$(TOP)/\$$(TCLSH) \$$(TOP)/g" \
		 -e "s|\./libtool|${LIBTOOL}|g" ${WRKSRC}/Makefile.in
	@${ECHO} "config_TARGET_TCL_INC=\"-I${PREFIX}/include/tcl${TCL_VERSION}\"" \
		> ${WRKSRC}/freebsd.hints
	@${ECHO} "config_TARGET_TCL_LIBS=\"-L${PREFIX}/lib -ltcl${TCL_VERSION:S/.//}\"" \
		>> ${WRKSRC}/freebsd.hints
.if defined(WITH_THREADS)
	@${ECHO} "config_TARGET_CFLAGS=\"-DTHREADSAFE=1 ${PTHREAD_LIBS}\"" \
		>> ${WRKSRC}/freebsd.hints
.endif

post-build:
.if !defined(NOPORTDOCS) && !defined(WITHOUT_DOCS)
	@${ECHO_MSG} "===> Building docs"
	@(cd ${WRKSRC} && ${GMAKE} ${MAKE_ARGS} doc)
.endif

post-install:
.if defined(WITH_TCL)
	@(cd ${WRKSRC} && ${GMAKE} install-tcl)
	${INSTALL_DATA} ${FILESDIR}/pkgIndex.tcl ${PREFIX}/lib/sqlite/
.endif
.if !defined(NOPORTDOCS) && !defined(WITHOUT_DOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/example.tcl ${EXAMPLESDIR}

.include <bsd.port.post.mk>
