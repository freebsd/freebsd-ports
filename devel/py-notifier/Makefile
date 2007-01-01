# New ports collection makefile for:	py-notifier
# Date created:		2006-12-31
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	notifier
PORTVERSION=	0.5.7
CATEGORIES=	devel python
MASTER_SITES=	# http://www.bitkipper.net/Downloads/pynotifier
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}_${PORTVERSION}-1

MAINTAINER=	lwhsu@lwhsu.org
COMMENT=	A generic notifier/event scheduler abstraction

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EXAMPLESDIR=	${TARGETDIR}/share/examples/py-${PORTNAME}

WRKSRC=		${WRKDIR}/py${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

do-fetch:
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
	${FETCH_CMD} -o "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}" "http://www.bitkipper.net/Downloads/pynotifier?action=AttachFile&do=get&target=${DISTFILES}"
.endif

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
