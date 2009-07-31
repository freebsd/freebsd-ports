# New ports collection makefile for:	openerp-server
# Date created:		27 February 2009
# Whom:			Wen Heping<wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	openerp-server
PORTVERSION=	5.0.1
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	http://openerp.com/download/stable/source/
DISTNAME=	${PORTNAME}-${PORTVERSION}-0

MAINTAINER=	wenheping@gmail.com
COMMENT=	Open source application ERP & CRM in Python using Postgresql

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_SITELIBDIR}/mx/__init__.py:${PORTSDIR}/lang/py-mx-base \
		${PYTHON_PKGNAMEPREFIX}psycopg2>0:${PORTSDIR}/databases/py-psycopg2 \
		${PYTHON_PKGNAMEPREFIX}chart>0:${PORTSDIR}/graphics/py-chart \
		${PYTHON_PKGNAMEPREFIX}pydot>0:${PORTSDIR}/graphics/py-pydot \
		${PYTHON_PKGNAMEPREFIX}libxslt>0:${PORTSDIR}/textproc/py-libxslt \
		${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=			2.4+
USE_PYDISTUTILS=		yes
PYDISTUTILS_EGGINFO=		openerp_server-5.0.1_0-${PYTHON_VERSION:S/thon//}.egg-info

MAN1=		openerp-server.1
MAN5=		openerp_serverrc.5

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
	@${FIND} -s -d ${DOCSDIR} -type f | ${SED} 's#${PREFIX}/##g' >> ${TMPPLIST}
	@${FIND} -s -d ${DOCSDIR} -type d | ${SED} 's#${PREFIX}/#@dirrm #g' >> ${TMPPLIST}
.endif

	${INSTALL_MAN} ${WRKSRC}/man/openerp-server.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/openerp_serverrc.5 ${PREFIX}/man/man5

	@${ECHO} bin/openerp-server >> ${TMPPLIST}
	@${FIND} -s -d ${PYTHON_SITELIBDIR}/${PORTNAME} \
		-type f | ${SED} 's#${PREFIX}/##g' >> ${TMPPLIST}
	@${FIND} -s -d ${PYTHON_SITELIBDIR}/${PORTNAME} \
		-type d | ${SED} 's#${PREFIX}/#@dirrm #g' >> ${TMPPLIST}

.include <bsd.port.post.mk>
