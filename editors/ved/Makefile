# New ports collection makefile for:   ved
# Date created:        31 December 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ved
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.berlios.de/pub/ved/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small and fast screen-oriented editor

USE_REINPLACE=	yes
USE_GMAKE=	yes

MAN1=		ved.1

.include <bsd.port.pre.mk>

post-patch:
.for file in ved.h ved.1
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/ved/${file}
.endfor
.if ${ARCH} == amd64
	${CP} ${WRKSRC}/RULES/i386-freebsd-cc.rul ${WRKSRC}/RULES/amd64-freebsd-cc.rul
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ved/OBJ/${ARCH}-freebsd-cc/ved \
		${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ved/ved.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ved/ved.help ${DATADIR}

.include <bsd.port.post.mk>
