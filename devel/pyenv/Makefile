PORTNAME=	pyenv
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.6
CATEGORIES=	devel python

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Manage multiple versions of Python
WWW=		https://github.com/pyenv/pyenv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		cpe python shebangfix
CPE_VENDOR=	pyenv_project
USE_GITHUB=	yes

SHEBANG_FILES=	plugins/python-build/scripts/add_miniconda.py \
		plugins/python-build/scripts/add_miniforge.py

REINPLACE_ARGS=	-i ''
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} ${REINPLACE_ARGS} -e "s|\$${root}/completions|${DATADIR}/completions|g" \
		${WRKSRC}/libexec/pyenv-init
	@${RM} ${WRKSRC}/libexec/pyenv.orig
	@${FIND} ${WRKSRC} -name .gitignore -delete
	@${FIND} ${WRKSRC} -type d -empty -delete

do-install:
	CC="${CC}" ${WRKSRC}/src/${CONFIGURE_CMD}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC}/src
	( ${INSTALL_SCRIPT} ${WRKSRC}/libexec/* ${STAGEDIR}${PREFIX}/libexec/ )
	@${LN} -sf ../libexec/pyenv ${STAGEDIR}${PREFIX}/bin/pyenv
	@${MKDIR} ${STAGEDIR}${DATADIR}/completions
	( cd ${WRKSRC}/completions && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR}/completions )
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/pyenv.d
	( cd ${WRKSRC}/pyenv.d && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/etc/pyenv.d )
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/pyenv-plugins
	( cd ${WRKSRC}/plugins && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/libexec/pyenv-plugins )

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/pyenv-realpath.dylib

.include <bsd.port.mk>
