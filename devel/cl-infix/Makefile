# New ports collection makefile for:	infix
# Date created:				19 August 2006
# Whom:					Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	infix
DISTVERSION=	19960628
CATEGORIES=	devel lisp
MASTER_SITES=	http://ftp.linux.org.uk/pub/lisp/cclan/ \
		ftp://ftp.ntnu.no/pub/lisp/cclan/ \
		http://thingamy.com/cclan/ \
		http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=	cl-
DISTNAME=	${PORTNAME}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A lisp macro for reading math expressions in infix form

BUILD_DEPENDS=	${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf
RUN_DEPENDS=	${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
DOCSDIR?=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
CL_LIBDIR=	${PREFIX}/lib/common-lisp

NO_BUILD=	yes
NO_CDROM=	No fees or compensation can be charged

LPORTDOCS=	COPYING infix.3lisp

do-install:
	@${MKDIR} ${CL_LIBDIR}/infix
	@${INSTALL_DATA} ${WRKSRC}/infix.asd   ${CL_LIBDIR}/infix/
	@${INSTALL_DATA} ${WRKSRC}/*.cl ${CL_LIBDIR}/infix/
	@${INSTALL_DATA} ${WRKSRC}/infix.system ${CL_LIBDIR}/infix/
	@${LN} -sf ${CL_LIBDIR}/infix/infix.asd ${CL_LIBDIR}/system-registry/infix.asd
.if !defined(NOPORTDOCS)
.for FILE in ${LPORTDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
