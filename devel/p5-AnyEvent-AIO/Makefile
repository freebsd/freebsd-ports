# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	AnyEvent-AIO
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Asynchronous file and directory I/O with AnyEvent

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-AnyEvent>=3.4:devel/p5-AnyEvent \
		p5-IO-AIO>=3.0:devel/p5-IO-AIO

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
