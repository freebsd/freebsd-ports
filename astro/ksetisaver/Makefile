# New ports collection makefile for:	ksetisaver
# Date created:			18 January 2003
# Whom:				Scott A. Moberly <smoberly@karamazov.org>
#
# $FreeBSD$

PORTNAME=	ksetisaver
PORTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	astro kde
MASTER_SITES=	http://www.frozenlight.de/content/ksetisaver/

MAINTAINER=	smoberly@karamazov.org
COMMENT=	A KDE screensaver frontend for the Linux seti@home client

USE_KDELIBS_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e "s,/opt/seti,/var/db/setiathome," \
		${WRKSRC}/ksetisaver/configdialogR2.cpp \
		${WRKSRC}/ksetisaver/configdialogR2.ui \
		${WRKSRC}/ksetisaver/configuration.cpp \
		${WRKSRC}/po/de.po \
		${WRKSRC}/po/fr.po \
		${WRKSRC}/po/zh_CN.GB2312.po \
		${WRKSRC}/po/ksetisaver.pot

.include <bsd.port.mk>
