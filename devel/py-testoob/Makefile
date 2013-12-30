# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	testoob
PORTVERSION=	1.15
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	SF \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Testoob is an advanced unit testing framework for PyUnit

OPTIONS_DEFINE=	TWISTED HTML
TWISTED_DESC=	enable running in threads
HTML_DESC=	enable HTML output

# bypass infrastructure bug (taken from www/py-django)
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTWISTED}
USES+=		twisted
.endif

.if ${PORT_OPTIONS:MHTML}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Ft/Xml/__init__.py:${PORTSDIR}/textproc/py-4suite-xml
.endif

.include <bsd.port.post.mk>
