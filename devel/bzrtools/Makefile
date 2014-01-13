# Created by: Ulf Lilleengen
# $FreeBSD$

PORTNAME=	bzrtools
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/90479443/

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Extensions to devel/bzr

RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bzr

OPTIONS_DEFINE=	GRAPHVIZ RSYNC
GRAPHVIZ_DESC=	graphviz for graph-ancestry
RSYNC_DESC=	rsync for rspush
OPTIONS_DEFAULT=	RSYNC

WRKSRC=	${WRKDIR}/bzrtools
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	2.5.0
PYDISTUTILS_PKGNAME=	BzrTools

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGRAPHVIZ}
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
.endif

.if ${PORT_OPTIONS:MRSYNC}
RUN_DEPENDS+=	rsync:${PORTSDIR}/net/rsync
.endif

.include <bsd.port.mk>
