# New ports collection makefile for:	 autocd
# Date created:		11 Marth 2003
# Whom:			Dmitry Afanasiev <KOT@MATPOCKuH.Ru>
#
# $FreeBSD$
#

PORTNAME=	autocd
PORTVERSION=	3.01.02a
CATEGORIES=	audio sysutils
MASTER_SITES=	ftp://kot.spb.ru/pub/src/projects/autocd/

MAINTAINER=	KOT@MATPOCKuH.Ru
COMMENT=	Compact disc control utility

USE_REINPLACE=	yes
MAN1=		autocd.1 cdctl.1

post-patch:
.for file in Makefile
	@${REINPLACE_CMD} -e \
		's|/usr/local|${PREFIX}|g ; \
		s|CFLAGS=-Wall -O2 -pipe|CFLAGS?=${CFLAGS}|g' \
		${WRKSRC}/${file}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README.rus.html
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include	<bsd.port.mk>
