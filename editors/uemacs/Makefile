PORTNAME=	uemacs
PORTVERSION=	4.0
CATEGORIES=	editors
MASTER_SITES=	http://debian.physik.uni-essen.de/misc/memacs/disk2/
DISTNAME=	ue400dev

MAINTAINER=	mail@ozzmosis.com
COMMENT=	Full screen editor

# Converted from NO_CDROM
LICENSE=	uemacs
LICENSE_NAME=	uemacs
LICENSE_TEXT=	Resale allowed for media cost only
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

NO_WRKSUBDIR=	yes
USES=		dos2unix ncurses zip
EXTRACT_BEFORE_ARGS=	-Lq

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/src/*.c
	@${REINPLACE_CMD} -e 's|-ltermcap|${LDFLAGS} -lncurses|g' \
		${WRKSRC}/freebsd/makefile

.include <bsd.port.mk>
