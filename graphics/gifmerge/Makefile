# New ports collection makefile for:   gifmerge
# Date created:        20 Oct 1996
# Whom:                Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	gifmerge
PORTVERSION=	1.33
CATEGORIES=	graphics
MASTER_SITES=	http://the-labs.com/GIFMerge/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for making a GIF Animation

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/gifmerge

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o gifmerge gifmerge.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gifmerge ${PREFIX}/bin/gifmerge

.include <bsd.port.mk>
