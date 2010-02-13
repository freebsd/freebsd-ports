# New ports collection makefile for:    qwebirc
# Date created:                         12 January 2010
# Whom:                                 Terry (tabmow@freenode.net)
#
# $FreeBSD$
#

PORTNAME=	qwebirc
PORTVERSION=	0.1
CATEGORIES=	irc www
MASTER_SITES=	https://bitbucket.org/slug/qwebirc/get/
DISTNAME=	stable
EXTRACT_SUFX=	.gz

MAINTAINER=	tabmow@freenode.net
COMMENT=	Qwebirc is a fast, easy to use, free and open source Web IRC client

WRKSRC=	${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

USE_PYTHON=	yes
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/web/__init__.py:${PORTSDIR}/www/py-twistedWeb

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${PREFIX}/www/${PORTNAME}
	(cd ${WRKDIR}/${PORTNAME} && \
	${COPYTREE_SHARE} \* ${PREFIX}/www/${PORTNAME} )

post-install:
	@if [ ! -f ${PREFIX}/www/${PORTNAME}/config.py ]; then \
		${CP} -p ${PREFIX}/www/${PORTNAME}/config.py.example ${PREFIX}/www/${PORTNAME}/config.py ; \
	fi
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/${PORTNAME}

.include <bsd.port.post.mk>
