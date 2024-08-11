PORTNAME=	uemacs
PORTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	https://github.com/zoomosis/uemacs/releases/download/v4.0/
DISTNAME=	ue400dev

MAINTAINER=	mail@ozzmosis.com
COMMENT=	Full screen editor
WWW=		https://github.com/zoomosis/uemacs

# Converted from NO_CDROM
LICENSE=	uemacs
LICENSE_NAME=	uemacs
LICENSE_TEXT=	Resale allowed for media cost only
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

NO_WRKSUBDIR=	yes
USES=		dos2unix ncurses zip
EXTRACT_BEFORE_ARGS=	-Lq

CFLAGS+=		-Wno-int-conversion

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/src/*.c
	@${REINPLACE_CMD} -e 's|-ltermcap|${LDFLAGS} -lncurses|g' \
		${WRKSRC}/freebsd/makefile

.include <bsd.port.mk>
