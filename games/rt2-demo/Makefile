# Created by: se@FreeBSD.org
# $FreeBSD$

PORTNAME=	rt2_demo
PORTVERSION=	1.54b
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	http://cvsup.theplanet.com/distfiles/
DISTNAME=	rt2-demo
EXTRACT_SUFX=	.run
EXTRACT_ONLY=

MAINTAINER=	mva@FreeBSD.org
COMMENT=	The free demo of Railroad Tycoon II

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_LINUX=	yes

NO_STAGE=	yes
do-install:
		@${SH} ${FILESDIR}/do-install ${PREFIX} ${DISTDIR}

.include <bsd.port.mk>
