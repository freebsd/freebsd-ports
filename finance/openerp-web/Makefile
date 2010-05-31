# New ports collection makefile for:   openerp-web
# Date created:        11 January 2010
# Whom:                Borja Lopez<borja@pexego.es>
#
# $FreeBSD$
#

PORTNAME=	openerp-web
PORTVERSION=	5.0.6
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	http://openerp.com/download/stable/source/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	borja@pexego.es
COMMENT=	OpenERP Web Client

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cherrypy>0:${PORTSDIR}/www/py-cherrypy \
		${PYTHON_PKGNAMEPREFIX}Babel>0:${PORTSDIR}/devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}mako>0:${PORTSDIR}/textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}simplejson>0:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}formencode>0:${PORTSDIR}/www/py-formencode \
		${PYTHON_PKGNAMEPREFIX}parsing>0:${PORTSDIR}/devel/py-parsing \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}xlwt>0:${PORTSDIR}/textproc/py-xlwt
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GETTEXT=	yes

USE_PYTHON=		2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_NOEGGINFO=	yes

USE_RC_SUBR=	openerp-web

WRKSRC=		${WRKDIR}/openerp-client-web-${PORTVERSION}

post-install:
	@${INSTALL_DATA} ${FILESDIR}/openerp-web.conf ${PREFIX}/etc/openerp-web.conf.sample
	@${INSTALL_SCRIPT} ${FILESDIR}/openerp-web.wrapper ${PREFIX}/bin/openerp-web
	@${MKDIR} ${PREFIX}/openerp-web
	@${INSTALL_SCRIPT} ${FILESDIR}/openerp-web.py ${PREFIX}/openerp-web/openerp-web.py

.include <bsd.port.mk>
