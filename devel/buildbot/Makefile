# New ports collection makefile for:	buildbot
# Date created:		27 Sep 2005
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	buildbot
PORTVERSION=	0.7.5
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jkoshy@FreeBSD.org
COMMENT=	Automated system from compile/test cycle to validate code changes

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_TWISTED_RUN=	mail web words

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|/usr/bin/python|${PYTHON_CMD}|g'
	@${FIND} ${WRKSRC}/buildbot/test/mail -name \*.bak -delete

.include <bsd.port.mk>
