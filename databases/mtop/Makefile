# Created by: ijliao
# $FreeBSD$

PORTNAME=	mtop
PORTVERSION=	0.6.6
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	tut@nhamon.com.ua
COMMENT=	MySQL Monitoring Tool

RUN_DEPENDS=	p5-Curses>=0:${PORTSDIR}/devel/p5-Curses \
		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-Net>=0:${PORTSDIR}/net/p5-Net

PERL_CONFIGURE=	yes

MAN1=	mkill.1 mtop.1

post-patch:
	${RM} ${WRKSRC}/cpan2spec.pl

.include <bsd.port.mk>
