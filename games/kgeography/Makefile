# New ports collection makefile for:	kgeography
# Date created:							2004-12-01
# Whom:									arved
#
# $FreeBSD$

PORTNAME=		kgeography
PORTVERSION=	0.2
CATEGORIES=		games kde
MASTER_SITES=	http://download.berlios.de/kgeography/

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Geography learning tool

USE_BZIP2=			yes
USE_KDELIBS_VER=	3
GNU_CONFIGURE=		yes
USE_GMAKE=			yes
USE_REINPLACE=		yes

.include <bsd.port.pre.mk>

EXTRA_PATCHES=	${PORTSDIR}/x11/kde3/files/extrapatch-configure

post-patch:
	${REINPLACE_CMD} -e "s,xx,," ${WRKSRC}/po/Makefile.in

.include <bsd.port.post.mk>
