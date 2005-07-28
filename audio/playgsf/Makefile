# New ports collection makefile for:	playgsf
# Date created:				10 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	playgsf
PORTVERSION=	0.6
CATEGORIES=	audio
MASTER_SITES=	http://projects.raphnet.net/playgsf/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A command line player for gsf audio files

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
USE_GCC=	3.4+

# avoid a "of memory error" gcc bug
CFLAGS+=	-O0

PLIST_FILES=	bin/playgsf

ONLY_FOR_ARCHS=	i386	# contains x86 assembler

post-patch:
	@${REINPLACE_CMD} -e 's|^\(CFLAGS="\)\(-DLINUX\)|\1${CFLAGS} \2|' \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
