# New ports collection makefile for:   giftrans
# Date created:        14 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	giftrans
PORTVERSION=	1.12.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.rz.uni-karlsruhe.de/pub/net/www/tools/giftrans/
DISTFILES=	giftrans.c giftrans.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for GIF89a transparent option and interlace mode

DIST_SUBDIR=	giftrans
NO_WRKSUBDIR=	yes

MAN1=		giftrans.1
PLIST_FILES=	bin/giftrans

do-extract:
	@${MKDIR} ${WRKSRC}
	@for file in ${DISTFILES}; do \
		${CP} ${_DISTDIR}/$$file ${WRKSRC}; \
	done

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' ${WRKSRC}/giftrans.c

do-build:
	(cd ${WRKSRC}; ${CC} ${CFLAGS} giftrans.c -o giftrans)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/giftrans ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/giftrans.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
