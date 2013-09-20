# Created by: Mikhail Teterin
# $FreeBSD$

PORTNAME=	pgtcl
PORTVERSION=	2.0.0
CATEGORIES=	databases tcl
MASTER_SITES=	SF/pgtclng/pgtclng/${PORTVERSION}:src
MASTER_SITE_SUBDIR=	pgtclng
DISTNAME=	${PORTNAME}${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	TCL extension for accessing a PostgreSQL server (PGTCL-NG)

LICENSE=	BSD

USE_TCL=	yes
USE_PGSQL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} --with-tclinclude=${TCL_INCLUDEDIR}
LIBDIR=		${PREFIX}/lib/${PORTNAME}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
MANUALREL=	20110918

.if !defined(NOPORTDOCS)
EXTRACT_ONLY=	${_DISTFILES:M*tar.gz}
DISTFILES+=	pgtcldocs-${MANUALREL}.zip:doc
MASTER_SITES+=	SF/pgtclng/Manual/${MANUALREL}:doc
.endif

NO_STAGE=	yes
post-configure:
	${REINPLACE_CMD} -e 's,tclstub,tcl,g' \
	    -e 's,-DUSE_TCL_STUBS=1,-UUSE_TCL_STUBS,g' \
		${WRKSRC}/Makefile

do-install:
	${MKDIR} ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl	\
		${WRKSRC}/libpgtcl${PORTVERSION}.so ${LIBDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} -p ${DOCSDIR}
	${TAR} -xf ${DISTDIR}/${_DISTFILES:M*.zip} -C ${DOCSDIR} \
		--strip-components 1 --no-same-permission --no-same-owner
	${CHMOD} ${SHAREMODE} ${DOCSDIR}/*
.endif

.include <bsd.port.mk>
