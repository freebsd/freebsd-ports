# ex:ts=8
# New ports collection makefile for:	mp3asm
# Date created:			Jul 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mp3asm
PORTVERSION=	0.1.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${PERL} -pi -e "s,getprogname,_getprogname,g" ${WRKSRC}/src/mp3asm.c

.include <bsd.port.mk>
