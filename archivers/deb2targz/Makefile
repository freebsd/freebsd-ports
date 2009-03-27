# New ports collection makefile for:	deb2targz
# Date created:				27 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	deb2targz
PORTVERSION=	20021217
CATEGORIES=	archivers perl5
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A command-line utility for converting a Debian .deb file to a .tar.gz

USE_PERL5=	yes
NO_BUILD=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/deb2targz

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' \
		${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
