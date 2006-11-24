# New ports collection makefile for:	innotop
# Date created:				23 October 2006
# Whom:	      				Steven Kreuzer <skreuzer@f2o.org>
#
# $FreeBSD$
#

PORTNAME=	innotop
PORTVERSION=	0.1.160
CATEGORIES=	databases
MASTER_SITES=	http://www.xaprb.com/innotop/src/ \
		http://skreuzer.f2o.org/mirror/innotop/

MAINTAINER=	skreuzer@f2o.org
COMMENT=	A MySQL and InnoDB monitoring program

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/${PERL_ARCH}/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper

PERL_CONFIGURE=	yes

MAN1=		innotop.1
MAN3=		InnoDBParser.3

.include <bsd.port.mk>
