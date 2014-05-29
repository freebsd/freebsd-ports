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

LICENSE=	PostgreSQL
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

OPTIONS_DEFINE=	DOCS

.if defined(PGTCL_SLAVE)
USES=		pgsql:${PGTCL_SLAVE} tcl
.else
USES=		pgsql tcl
.endif
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} --with-tclinclude=${TCL_INCLUDEDIR}
LIBDIR=		${PREFIX}/lib/${PORTNAME}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
MANUALREL=	20110918

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
EXTRACT_ONLY=	${_DISTFILES:M*tar.gz}
DISTFILES+=	pgtcldocs-${MANUALREL}.zip:doc
MASTER_SITES+=	SF/pgtclng/Manual/${MANUALREL}:doc
.endif

PLIST_FILES=	lib/pgtcl/libpgtcl${PORTVERSION}.so \
		lib/pgtcl/pkgIndex.tcl
PLIST_DIRS=	lib/pgtcl
PORTDOCS=	*

post-configure:
	${REINPLACE_CMD} -e 's,tclstub,tcl,g' \
	    -e 's,-DUSE_TCL_STUBS=1,-UUSE_TCL_STUBS,g' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl	\
		${WRKSRC}/libpgtcl${PORTVERSION}.so ${STAGEDIR}${LIBDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TAR} -xf ${DISTDIR}/${_DISTFILES:M*.zip} -C ${STAGEDIR}${DOCSDIR} \
		--strip-components 1 --no-same-permission --no-same-owner
	${CHMOD} ${SHAREMODE} ${STAGEDIR}${DOCSDIR}/*
.endif

.include <bsd.port.mk>
