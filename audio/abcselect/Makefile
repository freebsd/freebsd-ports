# New ports collection makefile for:   abcselect
# Date created:			11 March 2002
# Whom:				Sue Blake <sue@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abcselect
PORTVERSION=	1.5
CATEGORIES=	audio
MASTER_SITES=	http://www.lautengesellschaft.de/cdmm/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extract parts, movements, etc from abc music files

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=	abcselect.1
PLIST_FILES=	bin/abcselect

post-patch:
	@${PERL} -pi -e "s,/usr/bin/perl,${SETENV} perl,g" ${WRKSRC}/abcselect

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/abcselect ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/abcselect.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
