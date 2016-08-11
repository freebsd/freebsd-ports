# Created by: Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	gifmerge
PORTVERSION=	1.33
DISTVERSIONSUFFIX=	.src
CATEGORIES=	graphics
MASTER_SITES=	SUNSITE/apps/graphics/convert

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for making a GIF Animation

USES=		tar:tgz

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/gifmerge

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o gifmerge gifmerge.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gifmerge ${STAGEDIR}${PREFIX}/bin/gifmerge

.include <bsd.port.mk>
