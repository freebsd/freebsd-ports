# New ports collection makefile for:	gawk
# Version required:	3.0.4
# Date created:		Mi  21 Okt 1998 13:53:18 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$

DISTNAME=	gawk-3.0.4
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gawk

MAINTAINER=	andreas@FreeBSD.org

MANUAL_PACKAGE_BUILD=	confuses zsh
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--program-prefix=g \
			--enable-bitops \
			--enable-non-decimal-data
MAN1= gawk.1

.include <bsd.port.mk>
