# Created by: Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	gifmerge
PORTVERSION=	1.33
CATEGORIES=	graphics
MASTER_SITES=	http://the-labs.com/GIFMerge/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for making a GIF Animation

BROKEN=		unfetchable

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/gifmerge

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o gifmerge gifmerge.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gifmerge ${STAGEDIR}${PREFIX}/bin/gifmerge

.include <bsd.port.mk>
