# New ports collection makefile for:   librep
# Version required:    0.8
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	librep-0.8
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.dcs.warwick.ac.uk/people/John.Harper/librep/

MAINTAINER=	nakai@FreeBSD.org

PLIST_SUB=	GNUHOST=${ARCH}--freebsd${OSREL}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-lxpg4"

.include <bsd.port.mk>
