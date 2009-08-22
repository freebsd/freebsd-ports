# ex:ts=8
#
# Ports collection makefile for:	kodos
# Date created:			Jun 8, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	kodos
PORTVERSION=	2.4.9
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	SF \
		http://dryice.name/computer/FreeBSD/distfiles/


MAINTAINER=	dryice@dryice.name
COMMENT=	The Python Regular Expression Debugger

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/qt.so:${PORTSDIR}/x11-toolkits/py-qt

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_NOEGGINFO=	yes

PLIST_FILES=	bin/kodos ${PYTHON_SITELIBDIR:S,^${PREFIX}/,,}/kodos.pth

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/setup.py

post-install:
	@${MV} -f ${PREFIX}/bin/kodos.py ${PREFIX}/bin/kodos
	@${FIND} ${PYTHON_SITELIBDIR}/kodos ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/kodos -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
