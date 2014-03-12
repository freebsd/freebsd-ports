# Created by: ABURAYER Rewsirow <rewsirow@ff.iij4u.or.jp>
# $FreeBSD$

PORTNAME=	luna
PORTVERSION=	1.9
CATEGORIES=	astro games
MASTER_SITES=	http://ftp.vector.co.jp/pack/dos/edu/science/space/
DISTNAME=	luna19s

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display the moon's phase

USES=		dos2unix lha
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/luna
MAKEFILE=	makefile

post-patch:
	@${REINPLACE_CMD} -e 's|varargs.h|stdarg.h|' ${WRKSRC}/iprintf/idoprnt.c

.include <bsd.port.mk>
