# Ports collection makefile for:	pyproj
# Date created:		Feb 8, 2007
# Whom:			TAOKA Fumiyoshi
#
# $FreeBSD$
#

PORTNAME=	pyproj
PORTVERSION=	1.8.1a
CATEGORIES=	graphics python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/p/pyproj/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	Pyrex wrapper to provide python interfaces to PROJ.4

LIB_DEPENDS=	proj.5:${PORTSDIR}/graphics/proj

WRKSRC=		${WRKDIR}/${PORTNAME}-1.8.1
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
MAKE_ENV=	PROJ_DIR=${LOCALBASE}

PORTDOCS=	Changelog README README.html

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
