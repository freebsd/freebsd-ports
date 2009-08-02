# New ports collection makefile for:	kimdaba
# Date created:			Sat Dec 13 16:09:29 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		kphotoalbum
PORTVERSION=		3.1.1
PORTREVISION=	5
CATEGORIES=		graphics kde
MASTER_SITES=		http://www.kphotoalbum.org/data/download/

MAINTAINER=		markus@FreeBSD.org
COMMENT=		Image database for KDE

LIB_DEPENDS=		kipi.2:${PORTSDIR}/graphics/libkipi \
			exiv2.7:${PORTSDIR}/graphics/exiv2 \
			kdcraw.4:${PORTSDIR}/graphics/libkdcraw

USE_KDELIBS_VER=	3
USE_BZIP2=		yes
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:22

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
