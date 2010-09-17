# New ports collection makefile for:	py-swift
# Date created:		2010-07-22
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	swift
PORTVERSION=	1.0.2
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gslin@gslin.org
COMMENT=	Highly available, distributed, eventually consistent object/blob store

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}eventlet>=0.9.8:${PORTSDIR}/net/py-eventlet \
		${PYTHON_PKGNAMEPREFIX}simplejson>=0:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}webob>=0.9.8:${PORTSDIR}/www/py-webob \
		${PYTHON_PKGNAMEPREFIX}xattr>=0:${PORTSDIR}/devel/py-xattr \
		rsync>=3.0:${PORTSDIR}/net/rsync

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	easy_install

post-install:
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${CP} -R ${WRKSRC}/etc/ ${PREFIX}/etc/${PORTNAME}

.include <bsd.port.mk>
