# New ports collection makefile for:	make
# Date Created:				2006-11-23
# Whom:					Shaun Amott <shaun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	make
PORTVERSION=	20050524
CATEGORIES=	devel sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	shaun
DISTNAME=	pmake-${PORTVERSION}

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	Berkeley make, back-ported to FreeBSD 4.x

WRKSRC=		${WRKDIR}/make

MAN1=		make.1

PLIST_FILES=	bin/make

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
IGNORE=		is already installed in the base system on FreeBSD 5.x and above
.endif

post-extract:
	@${REINPLACE_CMD} -e 's/^\(SRCS=	*\)/\1freebsd.o /' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's/<stdint\.h>/"freebsd.h"/' ${WRKSRC}/*.[ch]
	@${CP} ${FILESDIR}/freebsd.* ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/make ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
