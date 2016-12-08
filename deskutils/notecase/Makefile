# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	notecase
PORTVERSION=	1.9.8
PORTREVISION=	11
CATEGORIES=	deskutils textproc
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Hierarchical text notes manager

LICENSE=	BSD3CLAUSE

USES=		dos2unix gmake desktop-file-utils gettext pkgconfig shared-mime-info
USE_GNOME=	gtk20 gtksourceview2 gnomevfs2
USE_XORG=	x11

DOS2UNIX_REGEX=	.*\.(c|h|cpp)

MAKE_ARGS=	prefix=${PREFIX}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	help.ncd

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/notecase

.include <bsd.port.mk>
