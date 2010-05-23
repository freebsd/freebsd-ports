# New ports collection makefile for:	innotop
# Date created:				23 October 2006
# Whom:	      				Steven Kreuzer <skreuzer@f2o.org>
#
# $FreeBSD$
#

PORTNAME=	innotop
PORTVERSION=	1.7.2
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	A MySQL and InnoDB monitoring program

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/${PERL_ARCH}/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper

PERL_CONFIGURE=	yes

MAN1=		innotop.1

.include <bsd.port.mk>
