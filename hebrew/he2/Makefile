# Created by: nadav@libagent.org
# $FreeBSD$

PORTNAME=	he2
PORTVERSION=	0.61
PORTREVISION=	3
CATEGORIES=	hebrew editors
MASTER_SITES=	SF/${PORTNAME}/HebrewEditor/${PORTVERSION}

MAINTAINER=	cpm@fbsd.es
COMMENT=	Editor for editing (primarily LaTeX) Hebrew files

LICENSE=	GPLv2

RUN_DEPENDS=	iw-elmar-fonts>0:hebrew/elmar-fonts

USES=		gmake ncurses
GNU_CONFIGURE=	yes
ALL_TARGET=	-j${MAKE_JOBS_NUMBER}

post-patch:
	@${REINPLACE_CMD} -e 's|-lcurses -ltermcap|-lncurses|' \
		${WRKSRC}/he2/Makefile.in ${WRKSRC}/he2/Makefile.am

.include <bsd.port.mk>
