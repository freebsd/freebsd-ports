# ex:ts=8
# New ports collection makefile for:	clint
# Date created:			May 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	clint
PORTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

post-install:
	@install-info ${PREFIX}/info/clint.info ${PREFIX}/info/dir

.include <bsd.port.mk>
