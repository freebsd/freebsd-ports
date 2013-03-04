# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	buildbot
PORTVERSION=	0.8.6p1
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Automated system from compile/test cycle to validate code changes

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.1:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.7:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}migrate>=0.7:${PORTSDIR}/databases/py-migrate

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_TWISTED_RUN=	conch mail web words

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|/usr/bin/python|${PYTHON_CMD}|g'
	@${FIND} ${WRKSRC} -name \*.bak -delete

.include <bsd.port.mk>
