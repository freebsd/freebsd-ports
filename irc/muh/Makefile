# New ports collection makefile for:   muh
# Date created:        25 Sept 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	muh
PORTVERSION=	2.2.b.1
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=muh
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b./beta/}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A smart irc-bouncing-tool that remains on IRC all the time

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	"--enable-ipv6"

post-patch:
	@${REINPLACE_CMD} -e "s|=muh|=${PREFIX}/bin/muh|g" ${WRKSRC}/misc/muh-check

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/muh ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/misc/muh-check ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/misc/muh-rotatelog ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/misc/muhrc ${PREFIX}/share/skel/dot.muhrc

.include <bsd.port.mk>
