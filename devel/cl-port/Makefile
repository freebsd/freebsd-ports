# New ports collection Makefile for:	cl-port
# Date created:				12 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=		port
PORTVERSION=		2002.10.02.1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.linux.org.uk/pub/lisp/experimental/cclan/ \
			ftp://ftp.ntnu.no/pub/lisp/cclan/ \
			ftp://www.aarg.net/pub/cclan/ \
			http://thingamy.com/cclan/ \
			http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=		cl-
DISTNAME=		clocc-${PORTNAME}_2002-10-02-1

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Cross-Lisp portability package

BUILD_DEPENDS=		${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf
RUN_DEPENDS=		${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf

WRKSRC=			${WRKDIR}/clocc-${PORTNAME}
DOCSDIR?=		${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
NO_BUILD=		yes
CL_LIBDIR=		${PREFIX}/lib/common-lisp

do-install:
	${MKDIR} ${CL_LIBDIR}/port
	${INSTALL_DATA} ${WRKSRC}/clocc-port.asd ${CL_LIBDIR}/port/port.asd
	${INSTALL_DATA} ${WRKSRC}/port.system ${CL_LIBDIR}/port/port.system
	${INSTALL_DATA} ${WRKSRC}/*.lisp ${CL_LIBDIR}/port/
	${LN} -s ${CL_LIBDIR}/port/port.asd ${CL_LIBDIR}/system-registry/port.asd
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/port.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
