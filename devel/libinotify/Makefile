# New ports collection makefile for:		libinotify
# Date created:					2011-08-29
# Whom:						stas
#
# $FreeBSD$
#

PORTNAME=	libinotify
PORTVERSION=	20110829
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kevent based inotify compatible library

LICENSE=	MIT

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes

#
# Get rid of .la and static library files
#
post-configure:
	@${REINPLACE_CMD} -E -e \
	'/Install the pseudo-library/,/staticlibs=/s,^,#,' ${WRKSRC}/libtool

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
