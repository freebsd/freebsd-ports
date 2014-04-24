# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	openerp-server
PORTVERSION=	7.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	finance python
MASTER_SITES=	http://nightly.openerp.com/7.0/nightly/src/
DISTNAME=       openerp-${PORTVERSION}-${NIGHTLY}

MAINTAINER=	pakhom706@gmail.com
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
		${PYTHON_PKGNAMEPREFIX}xml>0:${PORTSDIR}/textproc/py-xml \
		${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}mako>0:${PORTSDIR}/textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}ldap2>0:${PORTSDIR}/net/py-ldap2 \
		${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab2
RUN_DEPENDS:=	${BUILD_DEPENDS}

NIGHTLY=	20140115-002435
NIGHTLY_=	${NIGHTLY:S/-/_/g}
WRKSRC=         ${WRKDIR}/openerp-${PORTVERSION}-${NIGHTLY}

USE_RC_SUBR=	openerpd
SUB_FILES=	openerp-server.conf pkg-message
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

USE_PYTHON=			yes
USE_PYDISTUTILS=		yes
PYDISTUTILS_NOEGGINFO=		yes
PYDISTUTILS_AUTOPLIST=		yes

USERS=		openerpd
GROUPS=		openerpd

post-install:
	@${REINPLACE_CMD} -e 's|site-packages/openerp-server|site-packages/openerp-${PORTVERSION}_${NIGHTLY_}-${PYTHON_VERSION:S/thon//}.egg/openerp|g' \
		${WRKDIR}/openerp-server.conf
	${INSTALL_DATA} ${WRKDIR}/openerp-server.conf \
		${STAGEDIR}${PREFIX}/etc/openerp-server.conf.sample
	@${ECHO} etc/openerp-server.conf.sample >> ${TMPPLIST}
	@${CHMOD} a+x ${STAGEDIR}${PREFIX}/bin/openerp-server

.include <bsd.port.mk>
