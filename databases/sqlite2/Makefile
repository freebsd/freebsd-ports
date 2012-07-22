# ex:ts=8
# New ports collection makefile for:	sqlite
# Date created:			Feb 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite
PORTVERSION=	2.8.17
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.sqlite.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An SQL database engine in a C library

BUILD_DEPENDS=	pkg-config>0:${PORTSDIR}/devel/pkg-config

USE_GMAKE=	YES
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	YES

CONFIGURE_ARGS=		--prefix=${PREFIX} --with-hints=freebsd.hints

DOCSDIR=	${PREFIX}/share/doc/sqlite2
EXAMPLESDIR=	${PREFIX}/share/examples/sqlite2

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}2

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude CVS

OPTIONS_DEFINE=	TCL THREADS DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCL}
USE_TCL=		83+
.else
.if ${PORT_OPTIONS:MDOCS}
USE_TCL_BUILD=		83+
. endif
.endif

.include <bsd.port.pre.mk>
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
PORTDOCS=	*
MAKE_ARGS+=	TCLSH=${TCLSH}
MAKE_ENV+=	TCL_VER=${TCL_VER}
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/tclsh \$$(TOP)/\$$(TCLSH) \$$(TOP)/g" \
		 -e "s|\./libtool|${LIBTOOL}|g" ${WRKSRC}/Makefile.in
.if ${PORT_OPTIONS:MTCL} || !empty(PORT_OPTIONS:MDOCS)
	@${ECHO} "config_TARGET_TCL_INC=\"-I${TCL_INCLUDEDIR}\"" \
		> ${WRKSRC}/freebsd.hints
	@${ECHO} "config_TARGET_TCL_LIBS=\"-L${PREFIX}/lib -ltcl${TCL_VER:S/.//}\"" \
		>> ${WRKSRC}/freebsd.hints
.else
	@${ECHO} "" > ${WRKSRC}/freebsd.hints
.endif
.if ${PORT_OPTIONS:MTHREADS}
	@${ECHO} "config_TARGET_CFLAGS=\"-DTHREADSAFE=1 ${PTHREAD_LIBS}\"" \
		>> ${WRKSRC}/freebsd.hints
.endif

post-build:
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "===> Building docs"
	@(cd ${WRKSRC} && ${GMAKE} ${MAKE_ARGS} doc)
.endif

post-install:
.if ${PORT_OPTIONS:MTCL}
	@(cd ${WRKSRC} && ${GMAKE} install-tcl)
	${INSTALL_DATA} ${FILESDIR}/pkgIndex.tcl ${PREFIX}/lib/sqlite/
.endif
.if ${PORT_OPTIONS:MTCL}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/example.tcl ${EXAMPLESDIR}

.include <bsd.port.post.mk>
