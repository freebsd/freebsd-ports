# New ports collection makefile for:	buildbot-slave
# Date created:		12 Jul 2010
# Whom:			Frederic Praca <frederic.praca@freebsd-fr.org>
#
# $FreeBSD$
#

PORTNAME=	buildbot-slave
PORTVERSION=	0.8.1
CATEGORIES=	devel python
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	buildbot/buildbot/${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Slave part of Buildbot, an continuous integration system

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
USE_TWISTED_RUN=	runner

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|/usr/bin/python|${PYTHON_CMD}|g'
	@${FIND} ${WRKSRC} -name \*.bak -delete

.include <bsd.port.mk>
