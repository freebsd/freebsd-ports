# ex:ts=8
# New ports collection makefile for:	mget
# Date created:			Sep 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mget
PORTVERSION=	1.3.0
CATEGORIES=	ftp
MASTER_SITES=	http://home.talkcity.com/LaGrangeLn/dbera/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

ALL_TARGET=	${PORTNAME}

post-patch:
	@${PERL} -pi -e "s,-lpthread,${PTHREAD_LIBS},g ; \
		s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mget ${PREFIX}/bin

.include <bsd.port.mk>
