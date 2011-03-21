# ports collection makefile for:	Berkeley DB v3
# Date created:				16 August 2000
# Whom:					Sergey Osokin aka oZZ <osa@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	db3
PORTVERSION=	3.3.11
PORTREVISION=	3
PORTEPOCH?=	1
CATEGORIES=	databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/
DISTNAME=	db-${PORTVERSION}
DIST_SUBDIR=	bdb

PATCH_SITES=	http://download.oracle.com/berkeley-db/patches/db/${PORTVERSION}/
PATCHFILES=	patch.${PORTVERSION}.1 patch.${PORTVERSION}.2

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	The Berkeley DB package, revision 3.3

PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		yes
CONFIGURE_SCRIPT=	../dist/configure
LIBTOOLFILES=		${CONFIGURE_SCRIPT}
CONFIGURE_ARGS=		--enable-compat185 \
			--enable-dump185 --enable-cxx \
			--enable-dynamic \
			--prefix=${PREFIX} \
			--includedir=${PREFIX}/include/db3
INSTALL_TARGET=		install_include install_lib install_utilities
.if !defined(NOPORTDOCS)
INSTALL_TARGET+=	install_docs docdir=${DOCSDIR}
PORTDOCS=		*
.endif

.if defined(WITH_TCL_VER) && !defined(WITH_TCL)
WITH_TCL:=	yes
.endif

.if defined(WITH_TCL)
USE_TCL=	83+
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_TCL)
CONFIGURE_ARGS+=	--enable-tcl --with-tcl=${TCL_LIBDIR}
PLIST_SUB+=	WITHTCL=""
.else
PLIST_SUB+=	WITHTCL="@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} -Ee 's|-l?pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-patch:
	@${CHMOD} 755 ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/../dist/configure

post-configure:
.if defined(WITH_TCL)
	@${REINPLACE_CMD} -e "s|TCFLAGS=.*|TCFLAGS=-I${TCL_INCLUDEDIR} -L${TCL_LIBDIR}|g" ${WRKSRC}/Makefile
.endif

post-install:
.if !defined(NOPORTDOCS)
	${RMDIR} ${DOCSDIR}/ref/splash
.endif

.include <bsd.port.post.mk>
