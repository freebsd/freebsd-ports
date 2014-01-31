# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	Device-USB
PORTVERSION=	0.35
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/
PKGNAMEPREFIX=	p5-

MAINTAINER=	josh.carroll@gmail.com
COMMENT=	Perl wrapper for libusb

BUILD_DEPENDS=	p5-Inline>=0:${PORTSDIR}/devel/p5-Inline
RUN_DEPENDS=	p5-Inline>=0:${PORTSDIR}/devel/p5-Inline

MAKE_JOBS_UNSAFE=yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
