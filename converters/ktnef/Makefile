# New ports collection makefile for:	ktnef
# Date created:		Sat Jun 28 01:09:48 CEST 2003
# Whom:			Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$
#

PORTNAME=		ktnef
PORTVERSION=		2.0
PORTREVISION=	1
CATEGORIES=		converters mail kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		brueffer@phoenix-systems.de
COMMENT=		TNEF viewer/extractor for KDE

USE_KDELIBS_VER=	3
USE_BZIP2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

post-extract:
	@${REINPLACE_CMD} -e 's|-pedantic ||g' ${WRKSRC}/configure

.include <bsd.port.mk>
