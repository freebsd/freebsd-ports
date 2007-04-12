# Ports collection makefile for:	pyproj
# Date created:		Feb 8, 2007
# Whom:			TAOKA Fumiyoshi
#
# $FreeBSD$
#

PORTNAME=	pyproj
PORTVERSION=	1.8.2
CATEGORIES=	graphics python
MASTER_SITES=	http://pyproj.googlecode.com/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	Pyrex wrapper to provide python interfaces to PROJ.4

WRKSRC=		${WRKDIR}/${DISTNAME:C/[a-z]$//}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PORTDOCS=	Changelog README README.html LICENSE_proj4

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/test/* ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
