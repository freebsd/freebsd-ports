# ports collection makefile for:	Berkeley DB v3
# Date created:				16 August 2000
# Whom:					Sergey Osokin aka oZZ <osa@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	db3
PORTVERSION=	3.3.11
PORTREVISION=	2
PORTEPOCH?=	1
CATEGORIES=	databases
MASTER_SITES=	http://downloads.sleepycat.com/
DISTNAME=	db-${PORTVERSION}
DIST_SUBDIR=	bdb

PATCH_SITES=	http://www.sleepycat.com/update/${PORTVERSION}/
PATCHFILES=	patch.${PORTVERSION}.1 patch.${PORTVERSION}.2
PATCH_DIST_STRIP=	-d ${WRKDIR}/${DISTNAME}

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	The Berkeley DB package, revision 3.3

WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

USE_REINPLACE=		yes
INSTALLS_SHLIB=		yes
USE_LIBTOOL_VER=	13
CONFIGURE_SCRIPT=	../dist/configure
LIBTOOLFILES=		${CONFIGURE_SCRIPT}
CONFIGURE_ARGS=		--enable-compat185 \
			--enable-dump185 --enable-cxx \
			--enable-dynamic \
			--prefix=${PREFIX} \
			--includedir=${PREFIX}/include/db3
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALL_TARGET=		install_include install_lib install_utilities
.if !defined(NOPORTDOCS)
INSTALL_TARGET+=	install_docs docdir=${DOCSDIR}
PORTDOCS=		*
.endif

.if defined(WITH_TCL_VER)
.if ${WITH_TCL_VER} == 8.4 || ${WITH_TCL_VER} == 8.3
CONFIGURE_ARGS+=	--enable-tcl --with-tcl=${LOCALBASE}/lib/tcl${WITH_TCL_VER}
LIB_DEPENDS+=	tcl${WITH_TCL_VER:S/.//}.1:${PORTSDIR}/lang/tcl${WITH_TCL_VER:S/.//}
PLIST_SUB+=	WITHTCL=""
.else
IGNORE=		"WITH_TCL_VER must be 8.4 or 8.3"
.endif
.else
PLIST_SUB+=	WITHTCL="@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} -Ee 's|-l?pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-patch:
	@${CHMOD} 755 ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/../dist/configure

post-configure:
.if defined(WITH_TCL_VER)
	@${REINPLACE_CMD} -e "s|TCFLAGS=.*|TCFLAGS=-I${LOCALBASE}/include/tcl${WITH_TCL_VER} -L${LOCALBASE}/lib/tcl${WITH_TCL_VER}|g" ${WRKSRC}/Makefile
.endif

post-install:
	${RM} -f ${PREFIX}/lib/libdb_tcl-3.3.la
.if !defined(NOPORTDOCS)
	${RMDIR} ${DOCSDIR}/ref/splash
.endif

.include <bsd.port.mk>
