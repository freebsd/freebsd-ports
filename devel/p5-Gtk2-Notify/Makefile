# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Gtk2-Notify
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lichray@gmail.com
COMMENT=	Perl interface to libnotify

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=0:${PORTSDIR}/devel/p5-Glib2 \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2
LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
