# New ports collection makefile for:	py-virtualenv
# Date created:		2007-10-10
# Whom:			Nicola Vitale	<nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	virtualenv
PORTVERSION=	1.7.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Virtual Python Environment builder

LICENSE=	MIT

PLIST_SUB=	PYVER=${PYTHON_VER} PIPVER=${PIPVER} DISTRIBUTEVER=${DISTRIBUTEVER} \
		PY2X=${PY2X}

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

PIPVER=	1.1
DISTRIBUTEVER=	0.6.27

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${INSTALL_DATA} index.txt ${DOCSDIR}/
.endif

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 320
PY2X=	"@comment "
# When Python version is 3.2+ we rewrite all the filenames
# of TMPPLIST that end with .py[co], so that they conform
# to PEP 3147 (see http://www.python.org/dev/peps/pep-3147/)
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
.else
PY2X=	""
.endif

.include <bsd.port.post.mk>
