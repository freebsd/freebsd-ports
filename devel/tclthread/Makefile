# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thread
PORTVERSION=	2.7.0
CATEGORIES=	devel
MASTER_SITES=	SF/tcl/Tcl/8.6.0
PKGNAMEPREFIX=	tcl
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Scripting level thread extension for Tcl

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/license.terms

USE_TCL=	84+

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
GNU_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/thread${PORTVERSION}

PLIST_SUB+=	VERSION="${PORTVERSION}"

INSTALL_TARGET=		install-binaries install-libraries
.if !defined(NO_INSTALL_MANPAGES)
MANN=		thread.n tpool.n tsv.n ttrace.n
INSTALL_TARGET+=	install-doc
.endif

OPTIONS_DEFINE=	GDBM DOCS
OPTIONS_DEFAULT=GDBM
GDBM_DESC=	Persistent shared variables using GDBM

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--with-tcl="${TCL_LIBDIR}"

.if ${PORT_OPTIONS:MGDBM}
LIB_DEPENDS+=		gdbm.4:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=	--with-gdbm
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/html
.for FILE in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.for FILE in thread.html tpool.html tsv.html ttrace.html
	${INSTALL_DATA} ${WRKSRC}/doc/html/${FILE} ${DOCSDIR}/html
.endfor
.endif

.include <bsd.port.post.mk>
