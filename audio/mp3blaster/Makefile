# New ports collection makefile for:	mp3blaster
# Version required:	2.0b16
# Date created:		5 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

DISTNAME=	mp3blaster-2.0b16
CATEGORIES=	audio
MASTER_SITES=	ftp://mud.stack.nl/pub/mp3blaster/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/players

MAINTAINER=	ports@FreeBSD.org

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 400010
LIB_DEPENDS=   ncurses.4:${PORTSDIR}/devel/ncurses
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"CPPFLAGS=-DPTHREADED_MPEG=1 -D_REENTERANT=1" \
		"LDFLAGS=-pthread"
USE_GMAKE=	yes
MAN1=		mp3blaster.1 nmixer.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/mp3blaster ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/mp3tag ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/nmixer/nmixer ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/mp3blaster.1 ${PREFIX}/man/man1
	@ ${INSTALL_MAN} ${WRKSRC}/nmixer.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
