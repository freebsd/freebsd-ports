# ex:ts=8
# New ports collection makefile for:	xparam
# Date created:			Dec 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xparam
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-dynamic
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e "s,-ldl,,g" ${WRKSRC}/configure

.include <bsd.port.mk>
