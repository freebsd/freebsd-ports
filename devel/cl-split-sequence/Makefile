# New ports collection Makefile for:	cl-split-sequence
# Date created:				10 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=		split-sequence
PORTVERSION=		20011114.1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.linux.org.uk/pub/lisp/experimental/cclan/ \
			ftp://ftp.ntnu.no/pub/lisp/cclan/ \
			ftp://www.aarg.net/pub/cclan/ \
			http://thingamy.com/cclan/ \
			http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=		cl-
DISTNAME=		${PORTNAME}_${PORTVERSION}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Partinitoning Common Lisp sequences

BUILD_DEPENDS=		${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf
RUN_DEPENDS=		${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf

WRKSRC=			${WRKDIR}/${PORTNAME}
NO_BUILD=		yes
CL_LIBDIR=		${PREFIX}/lib/common-lisp

do-install:
	${MKDIR} ${CL_LIBDIR}/split-sequence
	${INSTALL_DATA} ${WRKSRC}/split-sequence.lisp ${CL_LIBDIR}/split-sequence/
	${INSTALL_DATA} ${WRKSRC}/split-sequence.asd ${CL_LIBDIR}/split-sequence/
	${LN} -s ${CL_LIBDIR}/split-sequence/split-sequence.asd ${CL_LIBDIR}/system-registry/split-sequence.asd

.include <bsd.port.mk>
