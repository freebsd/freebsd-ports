# New ports collection makefile for:	p5-MyObject
# Date created:				14 November 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD: /tmp/pcvs/ports/databases/p5-MyObject/Attic/Makefile,v 1.9 2001-04-16 17:08:47 jedgar Exp $
#

PORTNAME=	MyObject
PORTVERSION=	1.2
PORTEPOCH=	1
CATEGORIES=	databases perl5
MASTER_SITES=	http://www.frontierworld.com/perl/
PKGNAMEPREFIX=	p5-
DISTNAME=	MyObject
EXTRACT_SUFX=	.pm

MAINTAINER=	jedgar@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Mysql.pm:${PORTSDIR}/databases/p5-Mysql

USE_PERL5=	yes
POD2MAN?=	/usr/bin/pod2man
NO_BUILD=	yes

MAN3=		MyObject.3

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}
	@(cd ${WRKSRC}; ${POD2MAN} MyObject.pm > MyObject.3)

do-install:
	${INSTALL_DATA} ${WRKSRC}/MyObject.pm ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}
	${INSTALL_MAN} ${WRKSRC}/MyObject.3 ${PREFIX}/man/man3

.include <bsd.port.mk>
