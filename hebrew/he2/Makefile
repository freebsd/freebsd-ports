# Created by: nadav@libagent.org
# $FreeBSD$

PORTNAME=	he2
PORTVERSION=	0.61
PORTREVISION=	2
CATEGORIES=	hebrew editors
MASTER_SITES=	SF/${PORTNAME}/HebrewEditor/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Editor for editing (primarily LaTeX) Hebrew files

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/hebrew:${PORTSDIR}/hebrew/elmar-fonts

USES=		gmake
GNU_CONFIGURE=	yes
ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu`

.include <bsd.port.mk>
