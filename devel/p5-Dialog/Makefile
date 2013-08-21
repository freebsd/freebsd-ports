# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	Dialog
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Perl interface to dialog(3)

USES=		perl5
USE_PERL5=	configure

MAN3=		Dialog.3

EXPIRATION_DATE=2014-01-01

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=		Does not build after FreeBSD 9.0. Use devel/p5-UI-Dialog instead.
.else
DEPRECATED=	Does not build after FreeBSD 9.0. Use devel/p5-UI-Dialog instead.
.endif

.include <bsd.port.post.mk>
