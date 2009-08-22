# New ports collection makefile for:	tclthread
# Date created:				Mon Apr 23 10:55:00 CET 2007
# Whom:					Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	thread
PORTVERSION=	2.6.5
PORTREVISION=	1
CATEGORIES=	devel tcl
MASTER_SITES=		SF/tcl/Thread%20Extension/${PORTVERSION}
PKGNAMEPREFIX=	tcl
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Thread extension for Tcl

USE_TCL=		84+
USE_TCL_THREADS=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
GNU_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/thread${PORTVERSION}

PLIST_SUB+=	VERSION="${PORTVERSION}"

INSTALL_TARGET=		install-binaries install-libraries
.if !defined(NO_INSTALL_MANPAGES)
MANN=		thread.n tpool.n tsv.n ttrace.n
INSTALL_TARGET+=	install-doc
.endif

OPTIONS=		GDBM	"include GDBM support"	on

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--with-tcl="${TCL_LIBDIR}"

.if defined(WITH_GDBM)
LIB_DEPENDS+=		gdbm.3:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=	--with-gdbm
CONFIGURE_ENV+=		gincdir="${LOCALBASE}/include" glibdir="${LOCALBASE}/lib"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/html
.for FILE in ChangeLog README license.terms
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.for FILE in thread.html tpool.html tsv.html ttrace.html
	${INSTALL_DATA} ${WRKSRC}/doc/html/${FILE} ${DOCSDIR}/html
.endfor
.endif

.include <bsd.port.post.mk>
