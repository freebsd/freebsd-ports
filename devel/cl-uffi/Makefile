# New ports collection makefile for:	uffi
# Date created:				19 August 2004
# Whom:					Matthew X. Economou <xenophon+fbsdports@irtnog.org>
#
# $FreeBSD$
#

PORTNAME=	uffi
PORTVERSION=	1.4.37
CATEGORIES=	devel
MASTER_SITES=	http://files.b9.com/uffi/
PKGNAMEPREFIX=	cl-

MAINTAINER=	xenophon+fbsdports@irtnog.org
COMMENT=	Universal Foreign Function Interface for Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf
RUN_DEPENDS=	${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf

DOCSDIR?=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
NO_BUILD=	yes
CL_LIBDIR=	${PREFIX}/lib/common-lisp

LPORTDOCS=	README NEWS TODO doc/uffi.pdf doc/html.tar.gz

do-install:
	${MKDIR} ${CL_LIBDIR}/uffi
	${MKDIR} ${CL_LIBDIR}/uffi/src
	${INSTALL_DATA} ${WRKSRC}/uffi.asd   ${CL_LIBDIR}/uffi/
	${INSTALL_DATA} ${WRKSRC}/src/*.lisp ${CL_LIBDIR}/uffi/src/
	${LN} -sf ${CL_LIBDIR}/uffi/uffi.asd ${CL_LIBDIR}/system-registry/uffi.asd
.if !defined(NOPORTDOCS)
.for i in ${LPORTDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
