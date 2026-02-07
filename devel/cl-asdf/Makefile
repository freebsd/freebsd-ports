PORTNAME=	asdf
DISTVERSION=	3.3.7
PORTEPOCH=	2
CATEGORIES=	devel lisp
MASTER_SITES=	https://asdf.common-lisp.dev/archives/
PKGNAMEPREFIX=	cl-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	System definition facility for Common Lisp
WWW=		https://common-lisp.net/project/asdf/

LICENSE=	MIT

USES=		cl gmake

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKSRC} && /bin/sh make-asdf.sh build_asdf)

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} \
		${STAGEDIR}${ASDF_PATHNAME}/build \
		${STAGEDIR}${ASDF_PATHNAME}/contrib \
		${STAGEDIR}${ASDF_PATHNAME}/uiop \
		${STAGEDIR}${ASDF_REGISTRY}
	${INSTALL_DATA} ${WRKSRC}/*.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/build/asdf.lisp ${STAGEDIR}${ASDF_PATHNAME}/build/
	${INSTALL_DATA} ${WRKSRC}/contrib/*.lisp ${STAGEDIR}${ASDF_PATHNAME}/contrib
	${INSTALL_DATA} ${WRKSRC}/uiop/*.lisp ${STAGEDIR}${ASDF_PATHNAME}/uiop
	${INSTALL_DATA} ${WRKSRC}/version.lisp-expr ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/asdf.asd ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/uiop/uiop.asd ${STAGEDIR}${ASDF_PATHNAME}/uiop
	${RLN} ${STAGEDIR}${ASDF_PATHNAME}/build/asdf.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${RLN} ${STAGEDIR}${ASDF_PATHNAME}/asdf.asd ${STAGEDIR}${ASDF_REGISTRY}
	${RLN} ${STAGEDIR}${ASDF_PATHNAME}/uiop/uiop.asd ${STAGEDIR}${ASDF_REGISTRY}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	(cd ${STAGEDIR}${DOCSDIR} && ${RM} .htaccess Changelog Makefile)

.include <bsd.port.mk>
