# New ports collection makefile for:	scummvm-tools
# Date created:				28 May 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scummvm-tools
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	games emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scummvm

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	Tools for use with the SCUMMVM game emulator

RUN_DEPENDS=	scummvm:${PORTSDIR}/games/scummvm

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's@:= -g -O@+= ${CFLAGS}@' \
		${WRKSRC}/Makefile

do-install:
.for i in extract rescumm descumm descumm6 simon1decr simon2mp3
	@${INSTALL_PROGRAM} ${WRKSRC}/$i ${PREFIX}/bin
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
