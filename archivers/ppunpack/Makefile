# New ports collection makefile for:	ppunpack
# Date created:				Sat 3 June 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	ppunpack
PORTVERSION=	1.0
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/pub/aminet/misc/unix/ \
		ftp://us.aminet.net/pub/aminet/misc/unix/
DISTNAME=	ppsmall-${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Decompresses Amiga PowerPacker files

RESTRICTED=	"No commercial redistribution"
NO_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/PPUnpack
MAKE_ARGS=	CC="${CC}" COPTS="${CFLAGS}"
PLIST_FILES=	bin/ppunpack
ALL_TARGET=	ppunpack

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ppunpack ${PREFIX}/bin

.include <bsd.port.mk>
