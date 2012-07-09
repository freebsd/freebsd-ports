# New ports collection makefile for:	py-postgresql
# Date created:				15 August 2009
# Whom:					Volodymyr Kostyrko <c.kworr@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTVERSION=	1.0.4
CATEGORIES=	databases python
MASTER_SITES=	http://python.projects.postgresql.org/files/ \
		http://limbo.xim.bz/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	postgresql

MAINTAINER=	c.kworr@gmail.com
COMMENT=	Python 3 compatible PostgreSQL database driver and tools

USE_XZ=	yes
USE_PGSQL=	yes
USE_PYTHON=	3.1+
USE_PYDISTUTILS=	yes

PYDISTUTILS_EGGINFO=	py_${PYDISTUTILS_PKGNAME:C/[^A-Za-z0-9.]+/_/g}-${PYDISTUTILS_PKGVERSION:C/[^A-Za-z0-9.]+/_/g}-${PYTHON_VERSION:S/thon//}.egg-info

.include <bsd.port.pre.mk>

# When Python version is 3.2+ we rewrite all the filenames
# of TMPPLIST that end with .py[co], so that they conform
# to PEP 3147 (see http://www.python.org/dev/peps/pep-3147/)
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
