# Ports collection makefile for:	IPython
# Date created:				Nov, 13	2003
# Whom:					Dryice Liu
#
# $FreeBSD$
#

PORTNAME=	ipython
PORTVERSION=	0.8.4
CATEGORIES=	devel python
MASTER_SITES=	http://ipython.scipy.org/dist/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dryice
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	An enhanced Interactive Python shell

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pexpect.py:${PORTSDIR}/misc/py-pexpect

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e "s#('data', docdirbase, docfiles),# #g" ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s#('data', pjoin(docdirbase, 'manual'),manfiles),# #g" ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s#('data', pjoin(docdirbase, 'manual/_static'),manstatic),# #g" ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s#('data',pjoin(docdirbase, 'extensions'),igridhelpfiles),# #g" ${WRKSRC}/setup.py
.endif

.if defined(NOPORTEXAMPLES)
	${REINPLACE_CMD} -e "s#('data', pjoin(docdirbase, 'examples'),examfiles),# #g" ${WRKSRC}/setup.py
.endif

.if defined(NOPORTEXAMPLES)
	${REINPLACE_CMD} -e "s#('data', manpagebase, manpages),# #g" ${WRKSRC}/setup.py
.else
MAN1=		ipython.1 pycolor.1
MANCOMPRESSED=	yes
.endif

.ifndef	NOPORTDOCS
PORTDOCS=	*
.endif

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 250
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_ctypes.so:${PORTSDIR}/devel/py-ctypes
.endif

.include <bsd.port.post.mk>
