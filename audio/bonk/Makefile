# ex:ts=8
# New ports collection makefile for:	bonk
# Date created:			Jun 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	bonk
PORTVERSION=	0.4
CATEGORIES=	audio
MASTER_SITES=	http://yoyo.cc.monash.edu.au/~pfh/bonk/

MAINTAINER=	ijliao@FreeBSD.org

post-patch:
	@${PERL} -pi -e "s,%%INSTALL_PROGRAM%%,${INSTALL_PROGRAM},g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
