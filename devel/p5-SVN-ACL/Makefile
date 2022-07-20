PORTNAME=	SVN-ACL
PORTVERSION=	0.02
PORTREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple ACL frontend for subversion

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-subversion>=0:devel/p5-subversion \
		p5-YAML>=0:textproc/p5-YAML

USES=		perl5 tar:tgz
USE_PERL5=	configure

.include <bsd.port.mk>
