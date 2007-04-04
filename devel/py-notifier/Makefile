# New ports collection makefile for:	py-notifier
# Date created:		2006-12-31
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	notifier
PORTVERSION=	0.5.8
CATEGORIES=	devel python
MASTER_SITES=	http://www.bitkipper.net/bytes/pynotifier/source/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}_${PORTVERSION}-1

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	A generic notifier/event scheduler abstraction

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EXAMPLESDIR=	${TARGETDIR}/share/examples/py-${PORTNAME}

WRKSRC=		${WRKDIR}/py${PORTNAME}-${PORTVERSION}

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/*.py ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
