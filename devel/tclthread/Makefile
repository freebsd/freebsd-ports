# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thread
PORTVERSION=	2.7.1
CATEGORIES=	devel
MASTER_SITES=	SF/tcl/Tcl/8.6.2
PKGNAMEPREFIX=	tcl
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Scripting level thread extension for Tcl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.terms

USES+=		tcl

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--exec-prefix=${PREFIX}
USE_LDCONFIG=	${PREFIX}/lib/thread${PORTVERSION}

PLIST_SUB+=	VERSION="${PORTVERSION}"

INSTALL_TARGET=	install-binaries install-libraries install-doc

OPTIONS_DEFINE=	GDBM DOCS
OPTIONS_DEFAULT=GDBM
GDBM_DESC=	Persistent shared variables using GDBM

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGDBM}
LIB_DEPENDS+=	libgdbm.so:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=--with-gdbm
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
	    '/^INSTALL_PROGRAM/s|$$| -s|; /^INSTALL_LIBRARY/s|$$| -s|' \
	    ${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
.for FILE in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.for FILE in thread.html tpool.html tsv.html ttrace.html
	${INSTALL_DATA} ${WRKSRC}/doc/html/${FILE} ${STAGEDIR}${DOCSDIR}/html
.endfor

.include <bsd.port.mk>
