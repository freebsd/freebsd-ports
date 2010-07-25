# New ports collection makefile for:	sharedance
# Date created:		2008-04-13
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	sharedance
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://download.pureftpd.org/pub/sharedance/

MAINTAINER=	gslin@gslin.org
COMMENT=	A daemon to centralize keys and associated data

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

CONFIGURE_ARGS=	--with-largefile
GNU_CONFIGURE=	yes
USE_BZIP2=	yes

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/php/*.php ${DATADIR}

.include <bsd.port.mk>
