# New ports collection makefile for:    klogoturtle
# Date created:                 2003-07-23
# Whom:                         Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	klogoturtle
PORTVERSION=	0.5
CATEGORIES=	lang kde
MASTER_SITES=	http://klogoturtle.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LOGO Interpreter for the KDE Desktop

USE_KDELIBS_VER=	3
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_REINPLACE=		yes

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g' ${WRKSRC}/configure

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
