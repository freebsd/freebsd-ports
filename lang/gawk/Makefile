# New ports collection makefile for:	gawk
# Version required:	3.0.3
# Date created:		Mi  21 Okt 1998 13:53:18 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.3 1998/11/13 07:42:20 asami Exp $

DISTNAME=	gawk-3.0.3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gawk

MAINTAINER=	andreas@FreeBSD.ORG

MANUAL_PACKAGE_BUILD=	confuses zsh
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g --enable-bitops --enable-non-decimal-data

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gawk ${PREFIX}/bin

.include <bsd.port.mk>
