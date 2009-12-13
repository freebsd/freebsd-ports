# ex:ts=8
# Ports collection makefile for:	PyX
# Date created:			Jun 8, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	PyX
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A Python package for the creation of encapsulated PostScript figures

BUILD_DEPENDS=	kpsewhich:${PORTSDIR}/print/teTeX

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

PLIST_FILES=	etc/pyxrc

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|etc|g' ${WRKSRC}/setup.py

post-install:
	@${FIND} ${PYTHONPREFIX_SITELIBDIR}/pyx ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHONPREFIX_SITELIBDIR}/pyx -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/share/pyx ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/share/pyx -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
