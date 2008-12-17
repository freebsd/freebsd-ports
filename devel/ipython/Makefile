# Ports collection makefile for:	IPython
# Date created:				Nov, 13	2003
# Whom:					Dryice Liu
#
# $FreeBSD$
#

PORTNAME=	ipython
PORTVERSION=	0.9.1
CATEGORIES=	devel python
MASTER_SITES=	http://ipython.scipy.org/dist/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dryice
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	An enhanced Interactive Python shell

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pexpect.py:${PORTSDIR}/misc/py-pexpect \
		${PYCTYPES}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MAN1=		ipython.1 pycolor.1
MANCOMPRESSED=	yes

.ifndef	NOPORTDOCS
PORTDOCS=	*
.endif

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e "s#('data',pjoin(docdirbase,'extensions'),igridhelpfiles),# #g" ${WRKSRC}/setupbase.py
	${REINPLACE_CMD} -e "s# + manual_files##g" ${WRKSRC}/setupbase.py
.endif

.if defined(NOPORTEXAMPLES)
	${REINPLACE_CMD} -e "s# + example_files##g" ${WRKSRC}/setupbase.py
.endif

.include <bsd.port.mk>
