PORTNAME=	he2
PORTVERSION=	0.61
PORTREVISION=	3
CATEGORIES=	hebrew editors
MASTER_SITES=	SF/${PORTNAME}/HebrewEditor/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Editor for editing (primarily LaTeX) Hebrew files
WWW=		https://www.sourceforge.net/projects/he2/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Upstream last release was in 2001
EXPIRATION_DATE=	2024-01-16

RUN_DEPENDS=	iw-elmar-fonts>0:hebrew/elmar-fonts

USES=		gmake ncurses
USE_CXXSTD=	c++98

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lcurses -ltermcap|-lncurses|' \
		${WRKSRC}/he2/Makefile.in ${WRKSRC}/he2/Makefile.am

.include <bsd.port.mk>
