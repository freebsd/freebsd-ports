# New ports collection makefile for:	ftp/prozilla
# Date created:				Jan 24 2003
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	prozilla
PORTVERSION=	2.0.4
PORTREVISION=	2
CATEGORIES=	ftp www
MASTER_SITES=	http://prozilla.genesys.ro/downloads/prozilla/tarballs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ProZilla is a fast download accelerator

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	${CFLAGS} -I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

MAN1=		proz.1

.include <bsd.port.mk>
