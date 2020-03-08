# Created by: Ulf Lilleengen
# $FreeBSD$

PORTNAME=	bzrtools
PORTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/bzrtools/stable/${PORTVERSION}/+download/

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Extensions to devel/bzr

LICENSE=	GPLv2

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	bzr:devel/bzr

OPTIONS_DEFINE=	GRAPHVIZ RSYNC
GRAPHVIZ_DESC=	graphviz for graph-ancestry
RSYNC_DESC=	rsync for rspush

WRKSRC=		${WRKDIR}/bzrtools
USES=		python:2.7
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	BzrTools

GRAPHVIZ_RUN_DEPENDS=	dot:graphics/graphviz
RSYNC_RUN_DEPENDS=	rsync:net/rsync

.include <bsd.port.mk>
