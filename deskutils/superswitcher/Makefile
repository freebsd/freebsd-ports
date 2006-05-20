# New ports collection makefile for:	superswitcher
# Date Created:				02 Jan 2006
# Whom:					Remington Lang <MrL0Lz@gmail.com>
#
# $FreeBSD$

PORTNAME=	superswitcher
PORTVERSION=	0.3
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	browserbookapp
EXTRACT_SUFX=	.tgz

MAINTAINER=	MrL0Lz@gmail.com
COMMENT=	Alt-Tab replacement

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnomecommon
RUN_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnomecommon

USE_GMAKE=	yes
USE_GNOME=	gtk20 libwnck pango

post-patch:
	@${REINPLACE_CMD} -e 's/x11//g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/superswitcher ${PREFIX}/bin

.include <bsd.port.mk>
