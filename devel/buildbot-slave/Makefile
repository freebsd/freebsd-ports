# New ports collection makefile for:	buildbot-slave
# Date created:		12 Jul 2010
# Whom:			Frederic Praca <frederic.praca@freebsd-fr.org>
#
# $FreeBSD$
#

PORTNAME=	buildbot-slave
PORTVERSION=	0.8.6p1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Slave part of Buildbot, an continuous integration system

PROJECTHOST=	buildbot
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
USE_TWISTED_RUN=	runner
USE_RC_SUBR=	buildbot_slave

BB_USER?=	www

SUB_LIST=	BB_USER=${BB_USER} \
		PYTHON_CMD=${PYTHON_CMD}

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|/usr/bin/python|${PYTHON_CMD}|g'
	@${FIND} ${WRKSRC} -name \*.bak -delete

.include <bsd.port.mk>
