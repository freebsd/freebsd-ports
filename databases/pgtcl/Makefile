# New ports collection makefile for:	pgtcl
# Date created:				February 13, 2007
# Whom:					Mikhail Teterin
#
# $FreeBSD$
#

PORTNAME=	pgtcl
PORTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	databases tcl
DISTNAME=	${PORTNAME}${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1545/:src

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	TCL extension for accessing a PostgreSQL server (PGTCL-NG)

USE_TCL=	yes
USE_PGSQL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} --with-tclinclude=${TCL_INCLUDEDIR}
LIBDIR=		${PREFIX}/lib/${PORTNAME}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
.if !defined(NOPORTDOCS)
EXTRACT_ONLY=	${_DISTFILES:M*tar.gz}
DISTFILES+=	pgtcldocs-20070115.zip:doc
MASTER_SITES+=	http://pgfoundry.org/frs/download.php/1228/:doc
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
.endif

post-configure:
	${REINPLACE_CMD} -e 's,tclstub,tcl,g' \
	    -e 's,-DUSE_TCL_STUBS=1,-UUSE_TCL_STUBS,g' \
		${WRKSRC}/Makefile

do-install:
	${MKDIR} ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl	\
		${WRKSRC}/libpgtcl${PORTVERSION}.so ${LIBDIR}
.if !defined(NOPORTDOCS)
	${UNZIP_CMD} -oj ${DISTDIR}/${_DISTFILES:M*.zip} -d ${DOCSDIR}
.endif

.include <bsd.port.mk>
