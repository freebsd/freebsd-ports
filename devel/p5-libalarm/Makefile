PORTNAME=	libalarm
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/Alarm
PKGNAMEPREFIX=	p5-

MAINTAINER=	delgod@portaone.com
COMMENT=	Allow multiple, queued alarms

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${RM} ${WRKSRC}/lib/Alarm/Concurrent.pm.orig

.include <bsd.port.mk>
