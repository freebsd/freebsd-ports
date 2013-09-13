# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pydasm
PORTVERSION=	1.5
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	libdasm
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	libdasm-${PORTVERSION}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python interface to libdasm

LICENSE=	BSD

WRKSRC_SUBDIR=	${PORTNAME}
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/das.py ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
