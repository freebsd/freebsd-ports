# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-DBus
PORTVERSION=	1.1.0
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Perl extension for the DBus message system

LIB_DEPENDS=	libdbus-1.so:devel/dbus
RUN_DEPENDS=	p5-XML-Twig>=0:textproc/p5-XML-Twig \
		p5-XML-Grove>=0:textproc/p5-XML-Grove \
		p5-Time-HiRes>=0:devel/p5-Time-HiRes

USES=		pkgconfig perl5
USE_PERL5=	configure

.include <bsd.port.mk>
