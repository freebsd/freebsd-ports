# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	autodie
PORTVERSION=	2.22
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Replace functions with ones that succeed or die with lexical scope

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-BSD-Resource>=0:${PORTSDIR}/devel/p5-BSD-Resource \
		p5-IPC-System-Simple>=0:${PORTSDIR}/devel/p5-IPC-System-Simple

NO_STAGE=	yes
USES=		perl5
USE_PERL5=	configure

MAN3=		Fatal.3 \
		autodie.3 \
		autodie::exception.3 \
		autodie::exception::system.3 \
		autodie::hints.3 \
		autodie::skip.3

.include <bsd.port.mk>
