# New ports collection makefile for:	kmago
# Date created:				26 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kmago
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	ftp kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kmago

MAINTAINER=	demon@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

USE_KDELIBS_VER=2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${PERL} -pi -e 's#lqt#lqt2#g' ${WRKSRC}/configure ${WRKSRC}/kmago/Makefile.in
	@${PERL} -pi -e 's#/usr/bin#${LOCALBASE}/bin#g' ${WRKSRC}/kmago/ktransferwgetimpl.cpp

.include <bsd.port.mk>
