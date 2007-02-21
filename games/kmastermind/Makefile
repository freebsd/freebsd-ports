# New ports collection Makefile for:	kmastermind
# Date created:				2006-12-09
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kmastermind
PORTVERSION=	2.2
CATEGORIES=	games kde
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/
DISTNAME=	20292-${PORTNAME}-${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Mastermind game designed for K Desktop Environment

BUILD_DEPENDS=		${NONEXISTENT}:${PORTSDIR}/x11/kdelibs3:extract

USE_AUTOTOOLS=		automake:19:env autoconf:259:env libtool:15
USE_PERL5_BUILD=	yes
USE_KDELIBS_VER=	3
USE_BZIP2=		yes
WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile
.endif

pre-configure:
	${LN} -sfh \
		`cd ${PORTSDIR}/x11/kdelibs3 && ${MAKE} -V WRKSRC`/admin \
		${WRKSRC}/admin
	${TOUCH} ${WRKSRC}/NEWS
	cd ${WRKSRC}; ${MAKE} -f admin/Makefile.common cvs

.include <bsd.port.post.mk>
