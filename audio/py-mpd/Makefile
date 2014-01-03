# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpd
PORTVERSION=	0.3.0
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python MPD client library

USE_PYTHON=	yes
NO_STAGE=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python_mpd

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/commands.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
