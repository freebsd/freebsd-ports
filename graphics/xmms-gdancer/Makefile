# New ports collection makefile for:	xmms-gdancer
# Date created:			2. Jul 2001
# Whom:				Alexander@Leidinger.net
#
# $FreeBSD$
#

PORTNAME=	xmms-gdancer
PORTVERSION=	0.4.6
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://www.travisemslander.com/gdancer/files/
DISTNAME=	gdancer-$(PORTVERSION)

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS Visualization plugin, displays dancing figures

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/xmms/Visualization/gdancer.so

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/configure

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/gdancer.so ${PREFIX}/lib/xmms/Visualization
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
