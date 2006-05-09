# ex:ts=8
# Ports collection makefile for:	py-yaml
# Date created:			Jan 3, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yaml
PORTVERSION=	3.01
CATEGORIES=	devel python
MASTER_SITES=	http://pyyaml.org/download/pyyaml/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyYAML-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python YAML parser

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/yaml ! -type d | \
		${SED} -e "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/yaml -type d | ${SORT} -r | \
		${SED} -e "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.mk>
