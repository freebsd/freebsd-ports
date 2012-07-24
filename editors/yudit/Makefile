# New ports collection makefile for:	yudit
# Date created:		October 3, 1998
# Whom:			rch@richard.eu.org
#
# $FreeBSD$
#

PORTNAME=	yudit
PORTVERSION=	2.9.2
CATEGORIES=	editors converters print
MASTER_SITES=	http://yudit.org/download/ \
		SUNSITE/apps/editors/X

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-lingual Unicode text editor with TTF support

CONFLICTS=	netatalk-[0-9]*

USE_XORG=	x11
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LC_ALL=
MAKE_ENV=	LC_ALL=
MAKE_JOBS_UNSAFE=	yes

MAN1=		mytool.1 uniconv.1 uniprint.1

.include <bsd.port.mk>
