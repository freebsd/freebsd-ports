# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	setproctitle
PORTVERSION=	1.1.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Allow customization of the process title

LICENSE=	BSD

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PORTNAME}.so

PORTDOCS=	COPYRIGHT HISTORY.rst README.rst

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
