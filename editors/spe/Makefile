# New ports collection makefile for:	SPE
# Date created:		2005-10-12
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	SPE
PORTVERSION=	0.8.2.a
CATEGORIES=	editors devel python
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	python
DISTNAME=	${PORTNAME}-${PORTVERSION}-wx2.6.1.0

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Stani's Python Editor

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_WX=		2.6
WX_COMPS=	python

OPTIONS=	ENCRYPTED_DEBUG "Enable encrypted debug in SPE" off

SPEDOCS=	${PYTHON_SITELIBDIR}/_${PORTNAME:L}/doc
SPEXAMPLES=	${PYTHON_SITELIBDIR}/_${PORTNAME:L}/examples
WINSCRIPT=	spe_wininst.py

LN_OPTS=	-sf
RM_OPTS=	-R

post-install:
# documentation
.if !defined (NOPORTDOCS)
	@${MV} ${SPEDOCS} ${DOCSDIR} && \
	${LN} ${LN_OPTS} ${DOCSDIR} ${SPEDOCS}
.else
	@${RM} ${RM_OPTS} ${SPEDOCS}
.endif
# examples
	@${MV} ${SPEXAMPLES} ${EXAMPLESDIR} && \
	${LN} ${LN_OPTS} ${EXAMPLESDIR} ${SPEXAMPLES}
# rm Windows script
	@${RM} ${PREFIX}/bin/${WINSCRIPT}

.include <bsd.port.pre.mk>

.if defined(WITH_ENCRYPTED_DEBUG)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto
.endif

.include <bsd.port.post.mk>
