# Created by: nadav@libagent.org
# $FreeBSD$

PORTNAME=	he2
PORTVERSION=	0.61
PORTREVISION=	3
CATEGORIES=	hebrew editors
MASTER_SITES=	SF/${PORTNAME}/HebrewEditor/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Editor for editing (primarily LaTeX) Hebrew files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	iw-elmar-fonts>0:hebrew/elmar-fonts

USES=		gmake ncurses
GNU_CONFIGURE=	yes
USE_CXXSTD=	c++98

post-patch:
	@${REINPLACE_CMD} -e 's|-lcurses -ltermcap|-lncurses|' \
		${WRKSRC}/he2/Makefile.in ${WRKSRC}/he2/Makefile.am

.include <bsd.port.mk>
