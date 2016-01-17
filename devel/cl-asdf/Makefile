# Created by: Henrik Motakef <henrik.motakef@web.de>
# $FreeBSD$

# The source tarball was obtained from the project's GIT repository:
# wget -O asdf-2.017.tar.gz "http://common-lisp.net/gitweb?p=projects/asdf/asdf.git;a=snapshot;h=db16d0cc1a15697f831bcacc9429cc578304b6cb;sf=tgz"

PORTNAME=	asdf
PORTVERSION=	2.017
PORTEPOCH=	2
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
MASTER_SITES=	LOCAL/olgeni

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	System definition facility for Common Lisp

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

SUB_FILES+=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME}
	@${MKDIR} ${STAGEDIR}${ASDF_REGISTRY}
	@${INSTALL_DATA} ${WRKSRC}/*.lisp ${STAGEDIR}${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/*.asd ${STAGEDIR}${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/asdf.asd ${STAGEDIR}${ASDF_REGISTRY}
	@${SED}	-i '' -e 's|%%PREFIX%%|${PREFIX}|' ${STAGEDIR}${ASDF_PATHNAME}/asdf.lisp
	@${SED}	-e 's|%%ASDF_PATHNAME%%|${ASDF_PATHNAME}/asdf|' \
		-e 's|%%ASDF_REGISTRY%%|${ASDF_REGISTRY}|' \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		${FILESDIR}/asdf-init.lisp > \
		${STAGEDIR}${PREFIX}/etc/asdf-init.lisp.default

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.cl-asdf.mk>
.include <bsd.port.mk>
