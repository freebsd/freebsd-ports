# New ports collection makefile for:	bisongen
# Date created:				August 8th 2005
# Whom:					Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	bisongen
PORTVERSION=	0.8.0b1
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.fourthought.com/pub/BisonGen/
DISTNAME=	BisonGen-${PORTVERSION}

MAINTAINER=	frerich.raabe@gmx.de
COMMENT=	A general-purpose parser generator for Python

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/simple/* ${EXAMPLESDIR}

.include <bsd.port.mk>
