# Ports collection makefile for:	bzrtools
# Date created:		3 November 2005
# Whom:			Ulf Lilleengen
#
# $FreeBSD$
#

PORTNAME=	bzrtools
PORTVERSION=	1.3.0
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/bzrtools/trunk/${PORTVERSION}/+download/

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Extensions to devel/bazaar-ng

RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng

OPTIONS=	GRAPHVIZ "Enable graphviz for graph-ancestry" on \
		RSYNC    "Enable rsync for rspush" on \
		BAZ      "Enable baz-import" off

WRKSRC=	${WRKDIR}/bzrtools
USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	BzrTools

.include <bsd.port.pre.mk>

.if defined(WITH_GRAPHVIZ)
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
.endif

.if defined(WITH_RSYNC)
RUN_DEPENDS+=	rsync:${PORTSDIR}/net/rsync
.endif

.if defined(WITH_BAZ)
RUN_DEPENDS+=	baz:${PORTSDIR}/devel/bazaar
.endif

.include <bsd.port.post.mk>
