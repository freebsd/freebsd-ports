# New ports collection makefile for:	logjam2
# Date created:				30 Oct 2002
# Whom:					michael johnson <ahze@rgv.net>
#
# $FreeBSD$
#

PORTNAME=	logjam2
PORTVERSION=	4.0.0
CATEGORIES=	deskutils
MASTER_SITES=	http://logjam.danga.com/download/

MAINTAINER=	ahze@rgv.net

LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl \
		gtkspell.0:${PORTSDIR}/textproc/gtkspell2

MAN1=		logjam.1

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
