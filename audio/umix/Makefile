# New ports collection makefile for:   umix
# Date created:        24 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	umix
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	greid@ukug.uk.freebsd.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC="$(CC) -I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib -lintl"

MAN1=		umix.1

.include <bsd.port.mk>
