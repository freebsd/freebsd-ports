# New ports collection makefile for:	py-stevedore
# Date created:		2012-08-19
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stevedore
PORTVERSION=	0.3
#PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Manage dynamic plugins for Python applications

OPTIONS_DEFINE=	DOCS
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz \
		sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
PYDISTUTILS_BUILD_TARGET+=	build_sphinx -a -E

post-install:
	@cd ${WRKSRC}/build/sphinx/html && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.if ${PYTHON_REL} >= 320
PYMAGICTAG=	${PYTHON_CMD} -c 'import imp; print(imp.get_tag())'
add-plist-post:
	@${AWK} '\
		/\.py[co]$$/ && !($$0 ~ "/" pc "/") {id = match($$0, /\/[^\/]+\.py[co]$$/); if (id != 0) {d = substr($$0, 1, RSTART - 1); dirs[d] = 1}; sub(/\.py[co]$$/,  "." mt "&"); sub(/[^\/]+\.py[co]$$/, pc "/&"); print; next} \
		/^@dirrm / {d = substr($$0, 8); if (d in dirs) {print $$0 "/" pc}; print $$0; next} \
		{print} \
		END {if (sp in dirs) {print "@dirrm " sp "/" pc}} \
		' \
		pc="__pycache__" mt="$$(${PYMAGICTAG})" sp="${PYTHON_SITELIBDIR:S,${PYTHONBASE}/,,g}" \
		${TMPPLIST} > ${TMPPLIST}.pyc_tmp
	@${MV} ${TMPPLIST}.pyc_tmp ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
