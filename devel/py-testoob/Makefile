# New ports collection makefile for:	testoob
# Date created:		Sun Oct 29 18:28:14 CET 2006
# Whom:			Tobias Roth <ports@fsck.ch>
#
# $FreeBSD$
#

PORTNAME=	testoob
PORTVERSION=	1.13
CATEGORIES=	devel python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@fsck.ch
COMMENT=	Testoob is an advanced unit testing framework for PyUnit

OPTIONS=	TWISTED "enable running in threads" off \
		HTML "enable HTML output" off
# bypass infrastructure bug (taken from www/py-django)
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

USE_BZIP2=	yes
USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_TWISTED)
USE_TWISTED=	yes
.endif

.if defined(WITH_HTML)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Ft/Xml/__init__.py:${PORTSDIR}/textproc/py-4suite-xml
.endif

.if ${PYTHON_REL} < 250
PLIST_SUB+=	PYTHON_CURRENT="@comment "
.else
EGG_INFO=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VERSION:S,^python,,}.egg-info
PLIST_SUB+=	PYTHON_CURRENT="" EGG_INFO=${EGG_INFO}
.endif

.include <bsd.port.post.mk>
