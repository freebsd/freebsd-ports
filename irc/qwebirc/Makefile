# New ports collection makefile for:    qwebirc
# Date created:                         12 January 2010
# Whom:                                 Terry (tabmow@freenode.net)
#
# $FreeBSD$
#

PORTNAME=	qwebirc
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	irc www
MASTER_SITES=	https://bitbucket.org/slug/qwebirc/get/
DISTNAME=	stable
EXTRACT_SUFX=	.gz

MAINTAINER=	tabmow@freenode.net
COMMENT=	Fast, easy to use, free, and open source web IRC client

WRKSRC=	${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

USE_PYTHON=	yes
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/web/__init__.py:${PORTSDIR}/www/py-twistedWeb
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/mail/__init__.py:${PORTSDIR}/mail/py-twistedMail
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/words/__init__.py:${PORTSDIR}/net-im/py-twistedWords
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/names/__init__.py:${PORTSDIR}/dns/py-twistedNames
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/twisted/conch/__init__.py:${PORTSDIR}/security/py-twistedConch

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
