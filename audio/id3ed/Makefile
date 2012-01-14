# New ports collection makefile for:	id3ed
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	id3ed
PORTVERSION=	1.10.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_NETBSD}

MAINTAINER=	turutani@scphys.kyoto-u.ac.jp
COMMENT=	An id3 tag editor for mp3 files

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

MAN1=		id3ed.1
PLIST_FILES=	bin/id3ed

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/id3ed ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/id3ed.1 ${MANPREFIX}/man/man1

post-patch:
	@${REINPLACE_CMD} '/main/s/unsigned int/int/' \
		${WRKSRC}/examples/demo_*.cpp
	@${REINPLACE_CMD} 's/\(iomanip\)\.h/\1/' ${WRKSRC}/configure
	@${REINPLACE_CMD} '/include.*/{ p; s//include <cstring>/; n;n;n; }' \
		${WRKSRC}/include/id3/id3lib_strings.h \
		${WRKSRC}/include/id3/writers.h

.include <bsd.port.mk>
