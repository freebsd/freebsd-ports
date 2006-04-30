# New ports collection makefile for:	kimdaba
# Date created:			Sat Dec 13 16:09:29 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		kphotoalbum
PORTVERSION=		2.2
CATEGORIES=		graphics kde
MASTER_SITES=		http://www.kphotoalbum.org/download/

MAINTAINER=		markus@FreeBSD.org
COMMENT=		Image database for KDE

LIB_DEPENDS=		kipi.1:${PORTSDIR}/graphics/libkipi

RUN_DEPENDS=		exiv2:${PORTSDIR}/graphics/exiv2
BUILD_DEPENDS=		${RUN_DEPENDS}

USE_KDELIBS_VER=	3
USE_BZIP2=		yes
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:15

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=			Does not compile
.endif

.include <bsd.port.post.mk>
