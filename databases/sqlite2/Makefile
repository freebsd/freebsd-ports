# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sqlite
PORTVERSION=	2.8.17
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://www.sqlite.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SQL database engine in a C library

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig readline
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-hints=freebsd.hints

DOCSDIR=	${PREFIX}/share/doc/sqlite2
EXAMPLESDIR=	${PREFIX}/share/examples/sqlite2

EXTRACT_AFTER_ARGS=	--exclude CVS

OPTIONS_DEFINE=	TCL THREADS DOCS EXAMPLES

.if !exists(/usr/lib/libreadline.so)
MAKE_ARGS=	READLINE_FLAGS="-DHAVE_READLINE=1 -I${LOCALBASE}/include -L${LOCALBASE}/lib"
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCL}
USES+=		tcl
.else
.if ${PORT_OPTIONS:MDOCS}
USES+=		tcl:build
.endif
.endif

.if ${PORT_OPTIONS:MTCL}
CATEGORIES+=	lang tcl
COMMENT+=	with TCL wrapper
MAKE_ARGS+=	TCLSH=${TCLSH}
MAKE_ENV+=	TCL_VER=${TCL_VER}
PLIST_SUB+=	WITH_TCLWRAPPER=""
.else
PLIST_SUB+=	WITH_TCLWRAPPER="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET=	doc
PORTDOCS=	*
MAKE_ARGS+=	TCLSH=${TCLSH}
MAKE_ENV+=	TCL_VER=${TCL_VER}
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/tclsh \$$(TOP)/\$$(TCLSH) \$$(TOP)/g" \
		${WRKSRC}/Makefile.in
.if ${PORT_OPTIONS:MTCL} || !empty(PORT_OPTIONS:MDOCS)
	@${ECHO} "config_TARGET_TCL_INC=\"-I${TCL_INCLUDEDIR}\"" \
		> ${WRKSRC}/freebsd.hints
	@${ECHO} "config_TARGET_TCL_LIBS=\"-L${PREFIX}/lib -ltcl${TCL_VER:S/.//}\"" \
		>> ${WRKSRC}/freebsd.hints
.else
	@${ECHO} "" > ${WRKSRC}/freebsd.hints
.endif
.if ${PORT_OPTIONS:MTHREADS}
	@${ECHO} "config_TARGET_CFLAGS=\"-DTHREADSAFE=1\"" \
		>> ${WRKSRC}/freebsd.hints
	@${ECHO} "config_TARGET_LIBS=\"-lpthread\"" \
		>> ${WRKSRC}/freebsd.hints
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sqlite
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsqlite.so
.if ${PORT_OPTIONS:MTCL}
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-tcl)
	${INSTALL_DATA} ${FILESDIR}/pkgIndex.tcl ${STAGEDIR}${PREFIX}/lib/sqlite
.endif
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/example.tcl ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
