# ex:ts=8
# New ports collection makefile for:	uds
# Date created:			Feb 27, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uds
PORTVERSION=	0.9.4
CATEGORIES=	devel
MASTER_SITES=	http://frost.flewid.de/dist/

MAINTAINER=	ijliao@FreeBSD.org

USE_AUTOMAKE=	yes
USE_AUTOCONF=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug

USE_GMAKE=	yes
USE_NEWGCC=	yes

INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/thread/Makefile.am

.include <bsd.port.mk>
