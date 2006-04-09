# New ports collection makefile for:	uffi
# Date created:				19 August 2004
# Whom:					Matthew X. Economou <xenophon+fbsdports@irtnog.org>
#
# $FreeBSD$
#

PORTNAME=	uffi
PORTVERSION=	1.5.9
CATEGORIES=	devel lisp
MASTER_SITES=	http://files.b9.com/uffi/
MASTER_SITE_SUBDIR=	. Archive
PKGNAMEPREFIX=	cl-

MAINTAINER=	xenophon+fbsdports@irtnog.org
COMMENT=	Universal Foreign Function Interface for Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf
RUN_DEPENDS=	${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf

DOCSDIR?=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
NO_BUILD=	yes
CL_LIBDIR?=	${LOCALBASE}/lib/common-lisp

LPORTDOCS=	AUTHORS ChangeLog INSTALL LICENSE Makefile.common NEWS README TODO \
		doc/uffi.pdf doc/html.tar.gz
LPORTEXAMPLES=	Makefile Makefile.msvc acl-compat-tester.lisp arrays.lisp atoifl.lisp \
		c-test-fns.c c-test-fns.lisp compress.lisp file-socket.lisp getenv.lisp \
		gethostname.lisp getshells.lisp gettime.lisp run-examples.lisp \
		strtol.lisp test-examples.lisp union.lisp

do-install:
	${MKDIR} ${CL_LIBDIR}/uffi
	${MKDIR} ${CL_LIBDIR}/uffi/src
	${INSTALL_DATA} ${WRKSRC}/uffi.asd   ${CL_LIBDIR}/uffi/
	${INSTALL_DATA} ${WRKSRC}/src/*.lisp ${CL_LIBDIR}/uffi/src/
	${LN} -sf ${CL_LIBDIR}/uffi/uffi.asd ${CL_LIBDIR}/system-registry/uffi.asd
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${LPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
	${MKDIR} ${DOCSDIR}/examples
.for i in ${LPORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${i} ${DOCSDIR}/examples/
.endfor
.endif

.include <bsd.port.mk>
