# New ports collection makefile for:  staticcharge
# Date created:        26 October 2001
# Whom:                Mahlon <mahlon@martini.nu>
#
# $FreeBSD$
#

PORTNAME=	staticcharge
PORTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	dns misc
MASTER_SITES=	http://www.staticcling.org/clients/
DISTNAME=	ChargeGTK-${PORTVERSION}

MAINTAINER=	mahlon@martini.nu
COMMENT=	A GTK client for the StaticCling dynamic DNS service

BUILD_DEPENDS=	wget:${PORTSDIR}/ftp/wget

PLIST_FILES=	bin/staticcharge
WRKSRC=		${WRKDIR}/staticcharge
USE_GNOME=	gtk12
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.ifdef DEBUG
CONFIGURE_ARGS+=  --enable-debug
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
