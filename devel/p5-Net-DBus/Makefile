# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-DBus
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension for the DBus message system

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-XML-Grove>=0:textproc/p5-XML-Grove \
		p5-XML-Twig>=0:textproc/p5-XML-Twig
LIB_DEPENDS=	libdbus-1.so:devel/dbus

USES=		perl5 pkgconfig
USE_PERL5=	configure

.include <bsd.port.mk>
