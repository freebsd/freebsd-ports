# New ports collection makefile for:	xmms-kde
# Date created:			27 April 2001
# Whom:				Jan Jungnickel <jan@jungnickel.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-kde
PORTVERSION=	0.6.5
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jan@jungnickel.com

LIB_DEPENDS=	xmms.3:${PORTSDIR}/audio/xmms

USE_KDELIBS_VER=2

#USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	${PERL} -pi -e "s|-lqt|-lqt2|;" ${WRKSRC}/configure

.include <bsd.port.mk>
