# New ports collection makefile for:	soribada
# Date created:		Thu Jan 31 12:56:39 KST 2002
# Whom:			CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	soribada
PORTVERSION=	0.3
CATEGORIES=	audio
MASTER_SITES=	http://soribada.kldp.org/

MAINTAINER=	cjh@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_X_PREFIX=	yes
USE_GTK=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
