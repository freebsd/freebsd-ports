# Ports collection makefile for:	pyproj
# Date created:		Feb 8, 2007
# Whom:			TAOKA Fumiyoshi
#
# $FreeBSD$
#

PORTNAME=	pyproj
PORTVERSION=	1.8.6
CATEGORIES=	graphics python geography
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	Pyrex wrapper to provide python interfaces to PROJ.4

WRKSRC=		${WRKDIR}/${DISTNAME:C/[a-z]$//}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PORTDOCS=	Changelog README README.html LICENSE_proj4
PORTEXAMPLES=	datum_shift.py geodtest.py sample.out \
		test.py test2.py test_transform.py

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.endif

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/test/$f ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
