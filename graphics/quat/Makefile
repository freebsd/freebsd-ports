# New ports collection makefile for:	quat
# Date created:				26 Aug 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	quat
PORTVERSION=	1.11
CATEGORIES=	graphics
MASTER_SITES=   http://www.physcip.uni-stuttgart.de/phy11733/download/

MAINTAINER=	dyeske@yahoo.com

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gui
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -E -e 's,-(march=pentium|O3|ffast-math),,g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e 's|-I\.[[:space:]]+-I\$$\(srcdir\)[[:space:]]+||' \
		${WRKSRC}/kernel/Makefile.in

.include <bsd.port.mk>
