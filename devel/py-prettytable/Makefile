# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	prettytable
PORTVERSION=	0.7.2
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP/source/P/PrettyTable
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Library for displaying tabular data in an ASCII table format

USES=		python
USE_PYTHON=	distutils autoplist

post-extract:
	@${CHMOD} -R a+rX ${WRKSRC}

.include <bsd.port.mk>
