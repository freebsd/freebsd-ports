# Created by: Mikhail Teterin
# $FreeBSD$

PORTNAME=	pgtcl
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	databases tcl
MASTER_SITES=	SF/pgtclng/pgtclng/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	TCL extension for accessing a PostgreSQL server (PGTCL-NG)

LICENSE=	PostgreSQL
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

.if defined(PGTCL_SLAVE)
USES=		pgsql:${PGTCL_SLAVE}
.else
USES=		pgsql
.endif

USES+=		tcl:tea
LIBDIR=		${PREFIX}/lib/${PORTNAME}
USE_LDCONFIG=	${LIBDIR}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
MANUALREL=	20171113

PLIST_FILES=	lib/pgtcl/libpgtcl${PORTVERSION}.so \
		lib/pgtcl/pkgIndex.tcl
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_DISTFILES=		pgtcldocs-${MANUALREL}.zip:doc
DOCS_MASTER_SITES=	SF/pgtclng/Manual/${MANUALREL}:doc

post-configure:
	${REINPLACE_CMD} -e 's,tclstub,tcl,g' \
	    -e 's,-DUSE_TCL_STUBS=1,-UUSE_TCL_STUBS,g' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl	\
		${WRKSRC}/libpgtcl${PORTVERSION}.so ${STAGEDIR}${LIBDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TAR} -xf ${DISTDIR}/${_DISTFILES:M*.zip} -C ${STAGEDIR}${DOCSDIR} \
		--strip-components 1 --no-same-permission --no-same-owner
	${CHMOD} ${SHAREMODE} ${STAGEDIR}${DOCSDIR}/*

.include <bsd.port.mk>
