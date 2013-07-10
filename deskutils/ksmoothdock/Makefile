# Created by: Arjan van Leeuwen <avleeuwen@piwebs.com>
# $FreeBSD$

PORTNAME=	ksmoothdock
PORTVERSION=	4.5
PORTREVISION=	8
CATEGORIES=	deskutils kde
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}_automake-1.9

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Dock program for KDE with smooth zooming

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_KDELIBS_VER=3
USES=		gmake
USE_AUTOTOOLS=	autoconf:env automake:env libtool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_PERL5_BUILD=yes

AUTOTOOLSFILES=	admin/cvs.sh

pre-configure:
	@cd ${WRKSRC}/admin && ${RM} -f ltmain.sh && ${CP} -f ${LTMAIN} .
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${GMAKE} -f admin/Makefile.common

.include <bsd.port.mk>
