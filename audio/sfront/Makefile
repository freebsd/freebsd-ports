# ex:ts=8
# New ports collection makefile for:	sfront
# Date created:			Nov 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sfront
PORTVERSION=	0.7.9
CATEGORIES=	audio
MASTER_SITES=	http://www.cs.berkeley.edu/~lazzaro/sa/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_BISON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/src
ALL_TARGET=	# empty

post-patch:
	@${PERL} -pi -e "s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/sfront ${PREFIX}/bin

.include <bsd.port.mk>
