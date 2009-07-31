# New ports collection makefile for:	ksmoothdock
# Date created: 			24 May 2004
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	ksmoothdock
PORTVERSION=	4.5
PORTREVISION=	4
CATEGORIES=	deskutils kde
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}_automake-1.9

MAINTAINER=	c0rn@o2.pl
COMMENT=	A dock program for KDE with smooth zooming

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262:env automake:19:env libtool:15:env
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_PERL5_BUILD=yes

pre-configure:
	@cd ${WRKSRC}/admin && ${RM} -f ltmain.sh && ${CP} -f ${LTMAIN} .
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${GMAKE} -f admin/Makefile.common

.include <bsd.port.mk>
