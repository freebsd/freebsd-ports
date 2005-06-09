# ex:ts=8
# Ports collection makefile for:	mtop
# Date created:			Dec 17, 2003
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	mtop
PORTVERSION=	0.6.6
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lesterm@mazpe.net
COMMENT=	MySQL Monitoring Tool

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Curses.pm:${PORTSDIR}/devel/p5-Curses \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/Net/Domain.pm:${PORTSDIR}/net/p5-Net

PERL_CONFIGURE=	yes

MAN1=	mkill.1 mtop.1

post-patch:
	${RM} ${WRKSRC}/cpan2spec.pl

.include <bsd.port.mk>
