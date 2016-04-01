# Created by: Rui Paulo <rpaulo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	App-SVN-Bisect
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Binary search through svn revisions

LICENSE=	ART20

BUILD_DEPENDS=	p5-IO-All>0:devel/p5-IO-All \
		p5-YAML-Syck>0:textproc/p5-YAML-Syck \
		${LOCALBASE}/bin/svn:devel/subversion
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Output>=0:devel/p5-Test-Output

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
