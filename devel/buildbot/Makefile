# New ports collection makefile for:	buildbot
# Date created:		27 Sep 2005
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	buildbot
PORTVERSION=	0.8.1
CATEGORIES=	devel python
MASTER_SITES=	SF

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Automated system from compile/test cycle to validate code changes

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.1:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
USE_TWISTED_RUN=	conch mail web words

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|/usr/bin/python|${PYTHON_CMD}|g'
	@${FIND} ${WRKSRC} -name \*.bak -delete

.include <bsd.port.mk>
