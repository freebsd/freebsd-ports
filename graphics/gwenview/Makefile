# New ports collection makefile for:	gwenview
# Date created:		22 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	gwenview
PORTVERSION=	0.17.1.a
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gwenview
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a/a/}

MAINTAINER=	stefan.jahn@nemesis-sektor.de
COMMENT=	An image viewer and browser for the KDE environment

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=	3

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_REINPLACE=	yes

MAN1=	gwenview.1

post-patch:
	@${REINPLACE_CMD} -e \
		's|xx||g' ${WRKSRC}/po/Makefile.in

.include <bsd.port.mk>
