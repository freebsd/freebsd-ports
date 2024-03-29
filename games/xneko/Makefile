PORTNAME=	xneko
PORTVERSION=	1.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	LOCAL/dinoex
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The classic cat-and-mouse

NO_WRKSUBDIR=	yes
USES=		imake xorg
USE_XORG=	x11
PLIST_FILES=	bin/xneko share/man/man6/xneko.6.gz

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.mk>
