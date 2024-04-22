PORTNAME=	SVN-Hooks
PORTVERSION=	1.36
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Framework for implementing Subversion hooks
WWW=		https://metacpan.org/release/SVN-Hooks

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Util>=0:devel/p5-Data-Util \
		p5-JIRA-REST>0:devel/p5-JIRA-REST \
		p5-SVN-Look>=0:devel/p5-SVN-Look \
		p5-SVN-Notify>=0:devel/p5-SVN-Notify \
		p5-XMLRPC-Lite>0:net/p5-XMLRPC-Lite
.if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS+=	subversion-lts>0:devel/subversion-lts
.else
RUN_DEPENDS+=	subversion>0:devel/subversion
.endif
TEST_DEPENDS=	p5-URI>=0:net/p5-URI

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
