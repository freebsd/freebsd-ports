# New ports collection makefile for:	ksmoothdock
# Date created: 			24 May 2004
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	ksmoothdock
PORTVERSION=	4.3
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}_automake1.9

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dock program for KDE with smooth zooming

USE_KDELIBS_VER=	3
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:259:env automake:19:env libtool:15:env
GNU_CONFIGURE=	yes

pre-configure:
	@cd ${WRKSRC}/admin && ${RM} -f ltmain.sh && ${CP} -f ${LTMAIN} .
	@cd ${WRKSRC} && ${GMAKE} -f admin/Makefile.common

.include <bsd.port.mk>
