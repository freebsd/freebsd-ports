# New ports collection makefile for: msrc0
# Date created:        17 November 1999
# Whom:                ajk@waterspout.com
#
# $FreeBSD$
#

PORTNAME=	msrc0
PORTVERSION=	0.7
CATEGORIES=	devel
MASTER_SITES=	ftp://archive.progeny.com/pundits/ \
		ftp://ftp.physics.purdue.edu/pub/pundits/
EXTRACT_SUFX=	.tgz

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Meta source fake-out script for building ksb tools

NO_BUILD=	yes
PLIST_FILES=	bin/makeme
WRKSRC=		${WRKDIR}/${PORTNAME}-0.6

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/makeme ${PREFIX}/bin

.include <bsd.port.mk>
