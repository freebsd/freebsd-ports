PORTNAME=	IO-Event
PORTVERSION=	0.814
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PLICEASE
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tied Filehandles for Nonblocking IO with Object Callbacks
WWW=		https://metacpan.org/release/IO-Event

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-List-SomeUtils>=0:devel/p5-List-SomeUtils
TEST_DEPENDS=	p5-AnyEvent>=0,1:devel/p5-AnyEvent \
		p5-EV>=0:devel/p5-EV \
		p5-Event>=0:devel/p5-Event

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	ANYEVENT EV EVENT
OPTIONS_DEFAULT=ANYEVENT EV EVENT
ANYEVENT_DESC=	Use AnyEvent as underlying event handler
EV_DESC=	Use EV as underlying event handler
EVENT_DESC=	Use Event as underlying event handler

ANYEVENT_BUILD_DEPENDS=	p5-AnyEvent>=0,1:devel/p5-AnyEvent
ANYEVENT_RUN_DEPENDS=	p5-AnyEvent>=0,1:devel/p5-AnyEvent
EV_BUILD_DEPENDS=	p5-EV>=0:devel/p5-EV
EV_RUN_DEPENDS=	p5-EV>=0:devel/p5-EV
EVENT_BUILD_DEPENDS=	p5-Event>=0:devel/p5-Event
EVENT_RUN_DEPENDS=	p5-Event>=0:devel/p5-Event

.include <bsd.port.mk>
