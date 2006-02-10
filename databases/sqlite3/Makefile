# ex:ts=8
# New ports collection makefile for:	sqlite
# Date created:			Feb 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

# By default, this port depends on TCL for building docs. If you want to build
# without TCL (and thus get no docs), define NOPORTDOCS.
# If you want to build the TCL wrapper, you have to define WITH_TCLWRAPPER=yes.

PORTNAME=	sqlite
PORTVERSION=	3.3.3
CATEGORIES=	databases
MASTER_SITES=	http://www.sqlite.org/

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	An SQL database engine in a C library w/ Tcl wrapper

USE_GMAKE=	YES
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=		--prefix=${PREFIX} --with-hints=freebsd.hints
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}3

OPTIONS=	TCLWRAPPER	"TCL wrapper for SQLITE" off

DOCSDIR=	${PREFIX}/share/doc/sqlite3
EXAMPLESDIR=	${PREFIX}/share/examples/sqlite3
PORTDOCS=	*

# Defaults, for building the docs:
TCL_V?=		8.4
MAKE_ARGS+=	TCLSH=tclsh${TCL_V}
MAKE_ENV+=	TCL_VER=${TCL_V}

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	tclsh${TCL_V}:${PORTSDIR}/lang/tcl${TCL_V:S/.//}
.endif

.if defined(WITH_TCLWRAPPER)
CATEGORIES+=	lang
WITH_TCL=	YES
.endif

.if defined(WITH_TCL)
PLIST_SUB+=		WITH_TCL=""
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib/tcl${TCL_V}
.else
PLIST_SUB+=		WITH_TCL="@comment "
CONFIGURE_ARGS+=	--disable-tcl
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/tclsh \$$(TOP)/\$$(TCLSH) \$$(TOP)/g" \
		-e "s|\./libtool|${LIBTOOL}|g" -e "s|\$${HAVE_TCL:1=tcl_install}||" \
		${WRKSRC}/Makefile.in
	@${ECHO} "config_TARGET_TCL_INC=\"-I${PREFIX}/include/tcl${TCL_V}\"" >${WRKSRC}/freebsd.hints
	@${ECHO} "config_TARGET_TCL_LIBS=\"-L${PREFIX}/lib -ltcl${TCL_V:S/.//}\"" >>${WRKSRC}/freebsd.hints

post-build:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===> Building docs"
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
.endif
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${FILESDIR}/example.tcl ${EXAMPLESDIR}

.include <bsd.port.post.mk>
