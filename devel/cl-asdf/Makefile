# New ports collection Makefile for:	cl-asdf
# Date created:				10 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

# The source tarball was obtained from the project's GIT repository:
# wget -O asdf-1.374.tar.gz "http://common-lisp.net/gitweb?p=projects/asdf/asdf.git;a=snapshot;h=f6dfe94d2836534a7be050127123cc16fee87c48;sf=tgz"

PORTNAME=	asdf
PORTVERSION=	1.374
PORTEPOCH=	1
CATEGORIES=	devel lisp
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	olgeni
PKGNAMEPREFIX=	cl-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A system definition facility for Common Lisp

SUB_FILES+=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes # Sources only
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${UNIQUENAME}

CL_LIBDIR=		${PREFIX}/lib/common-lisp
ASDF_SYSTEM_REGISTRY=	${CL_LIBDIR}/system-registry

do-install:
	@${MKDIR} ${CL_LIBDIR}/asdf
	@${MKDIR} ${ASDF_SYSTEM_REGISTRY}

	@${INSTALL_DATA} ${WRKSRC}/*.lisp ${CL_LIBDIR}/asdf/
	@${INSTALL_DATA} ${WRKSRC}/*.asd ${CL_LIBDIR}/asdf/

	@${LN} -sf ${CL_LIBDIR}/asdf/*.asd ${ASDF_SYSTEM_REGISTRY}

	@${SED}	-i '' -e 's|%%PREFIX%%|${PREFIX}|' ${CL_LIBDIR}/asdf/asdf.lisp
	@${SED}	-e 's|%%ASDF_PATHNAME%%|${CL_LIBDIR}/asdf/asdf|' \
		-e 's|%%ASDF_SYSTEM_REGISTRY%%|${ASDF_SYSTEM_REGISTRY}|' \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		${FILESDIR}/asdf-init.lisp > \
		${PREFIX}/etc/asdf-init.lisp.default
	@[ -f ${PREFIX}/etc/asdf-init.lisp ] || \
		${CP} ${PREFIX}/etc/asdf-init.lisp.default \
		${PREFIX}/etc/asdf-init.lisp
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	@${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCSDIR}/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
