# New ports collection makefile for:	ftp/prozilla
# Date created:				Jan 24 2003
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	prozilla
PORTVERSION=	2.0.3
PORTREVISION=	2
CATEGORIES=	ftp net
MASTER_SITES=	http://prozilla.genesys.ro/downloads/prozilla/tarballs/

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	ProZilla is a fast download accelerator

USE_BZIP2=	yes
USE_GETOPT_LONG=yes
USE_GETTEXT=	yes
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		proz.1

SUB_FILES=	pkg-message
PKGMESSAGE=	${FILESDIR}/pkg-message

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
