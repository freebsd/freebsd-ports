# Created by: mi@aldan.ziplink.net
# $FreeBSD$

PORTNAME=	xmdiary
PORTVERSION=	3.0.3
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	office
DISTFILES=	${DISTNAME}.tar.gz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Personal and group calendar utility

NO_CDROM=	Don't sell for profit
EXTRACT_ONLY=	${DISTNAME}.tar.gz
USE_MOTIF=	yes
USES=		imake
USE_GCC=	any
USE_XORG=	x11 xext xp xpm xt
MAN1=		xdaclunix.1 xdalarm.1 xdcustom.1 xddump.1 xdiary.1 xdinitdb.1 \
		xdlight.1 xdnotify.1 xdprformat.1 xdremind.1 xdremove.1 \
		xdrestore.1
MAKE_JOBS_SAFE=	yes

post-patch:
	@${ECHO_MSG} removing the "malloc.h" includes
	${SH} ${SCRIPTDIR}/nomalloc $(WRKSRC) 2>&1 > /dev/zero
	@${ECHO_MSG} removing unnecessary DependTarget from Imakefile-s
	${SH} ${SCRIPTDIR}/noextradepend $(WRKSRC) 2>&1 > /dev/zero
	${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		-e 's|CcCmd gcc|CcCmd ${CC}|' '${WRKSRC}/XDiary.tmpl'

.include <bsd.port.mk>
