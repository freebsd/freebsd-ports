# ex:ts=8
# Ports collection makefile for:	PyTables
# Date created:			Dec 19, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tables
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pytables
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytables-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A hierarchical database for Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numarray/__init__.py:${PORTSDIR}/math/py-numarray
LIB_DEPENDS=	hdf5.0:${PORTSDIR}/science/hdf5 \
		lzo.2:${PORTSDIR}/archivers/lzo \
		ucl.1:${PORTSDIR}/archivers/ucl
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/numarray/__init__.py:${PORTSDIR}/math/py-numarray

USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	bin/nctoh5 bin/ptdump bin/ptrepack

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE}," ${WRKSRC}/setup.py

post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/tables ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/tables -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.py ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
