# New ports collection Makefile for:	cl-asdf
# Date created:				10 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=		asdf
PORTVERSION=		2003.05.16
PORTREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav
PKGNAMEPREFIX=		cl-

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A system definition facility for Common Lisp

WRKSRC=			${WRKDIR}/${PORTNAME}
NO_BUILD=		yes # Sources only, see cl-asdf-[cmucl|sbcl|clisp]
CL_LIBDIR=		${PREFIX}/lib/common-lisp
ASDF_SYSTEM_REGISTRY=	${CL_LIBDIR}/system-registry
DOCSDIR=		${PREFIX}/share/doc/${UNIQUENAME}
EXAMPLESDIR=		${PREFIX}/share/examples/${UNIQUENAME}

do-install:
	${MKDIR} ${CL_LIBDIR}/asdf
	${MKDIR} ${ASDF_SYSTEM_REGISTRY}
	${INSTALL_DATA} ${WRKSRC}/asdf.lisp ${CL_LIBDIR}/asdf/
	${INSTALL_DATA} ${WRKSRC}/wild-modules.lisp ${CL_LIBDIR}/asdf/
	${SED}	-e 's|%%ASDF_PATHNAME%%|${CL_LIBDIR}/asdf/asdf|' \
		-e 's|%%ASDF_SYSTEM_REGISTRY%%|${ASDF_SYSTEM_REGISTRY}|' \
		${FILESDIR}/asdf-init.lisp > \
		${PREFIX}/etc/asdf-init.lisp.default
	[ -f ${PREFIX}/etc/asdf-init.lisp ] || \
		${CP} ${PREFIX}/etc/asdf-init.lisp.default \
		${PREFIX}/etc/asdf-init.lisp
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cl-asdf/
	${MKDIR} ${PREFIX}/share/examples/cl-asdf/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}/
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/test/* ${EXAMPLESDIR}/
.endif

post-install:
	@${CAT} ${MASTERDIR}/pkg-message

.include <bsd.port.mk>
