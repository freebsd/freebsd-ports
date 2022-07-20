PORTNAME=	yudit
PORTVERSION=	3.0.7
CATEGORIES=	editors converters print
MASTER_SITES=	http://yudit.org/download/ \
		SUNSITE/apps/editors/X

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Multi-lingual Unicode text editor with TTF support

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.TXT

CONFLICTS=	netatalk

USES=		gmake xorg
USE_XORG=	x11
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

PORTDATA=	*

DESKTOP_ENTRIES="Yudit" "${COMMENT}" "${PREFIX}/share/pixmaps/yudit.xpm" \
		"yudit" "Office;" false

post-install:
	${INSTALL_DATA} ${WRKSRC}/icons/SS_Yudit_XPM.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps/yudit.xpm

.include <bsd.port.mk>
