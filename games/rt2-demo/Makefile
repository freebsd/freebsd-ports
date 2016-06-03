# Created by: se@FreeBSD.org
# $FreeBSD$

PORTNAME=	rt2_demo
PORTVERSION=	1.54b
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	http://cvsup.theplanet.com/distfiles/
DISTNAME=	rt2-demo
EXTRACT_SUFX=	.run
EXTRACT_ONLY=	# empty

MAINTAINER=	mva@FreeBSD.org
COMMENT=	The free demo of Railroad Tycoon II

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_LINUX=	yes

do-install:
	@${SH} ${FILESDIR}/do-install ${STAGEDIR} ${PREFIX} ${DISTDIR}

.include <bsd.port.mk>
