# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	notecase
PORTVERSION=	1.9.8
PORTREVISION=	10
CATEGORIES=	deskutils textproc
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Hierarchical text notes manager

LICENSE=	BSD

USE_GNOME=	gtk20 gtksourceview2 gnomevfs2
USES=		gmake desktop-file-utils gettext pkgconfig shared-mime-info

USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(c|h|cpp)

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	help.ncd
INSTALL_TARGET=	install docinstall

post-patch:
	@${REINPLACE_CMD} -e 's|^prefix=.*|prefix=${PREFIX}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^docsdir=.*|docsdir=${DOCSDIR}|' \
		${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/notecase

.include <bsd.port.mk>
