PORTNAME=	SVN-ACL
PORTVERSION=	0.02
PORTREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple ACL frontend for subversion
WWW=		https://metacpan.org/release/SVN-ACL

BUILD_DEPENDS=	${RUN_DEPENDS}
.if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS=	p5-subversion-lts>=0:devel/p5-subversion
.else
RUN_DEPENDS=	p5-subversion>=0:devel/p5-subversion
.endif
RUN_DEPENDS+=	p5-YAML>=0:textproc/p5-YAML

USES=		perl5 tar:tgz
USE_PERL5=	configure

.include <bsd.port.mk>
