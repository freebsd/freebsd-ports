# ex:ts=8
# Ports collection makefile for:	py-reverse
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	reverse
PORTVERSION=	0.5.1
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.logilab.org/pub/pyreverse/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	A set of tools for reverse engineering Python code

BUILD_DEPENDS=	${PYXML}
RUN_DEPENDS=	${PYXML} \
		${PYTHONPREFIX_SITELIBDIR}/logilab/__init__.py:${PORTSDIR}/devel/py-logilab-common

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/logilab/pyreverse ! -type d | \
		${SED} -e 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/logilab/pyreverse -type d | ${SORT} -r | \
		${SED} -e 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/%%PYTHSON_SITELIBDIR%%/logilab 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
