# Created by: glarkin@
# $FreeBSD$

PORTNAME=	SVN-Notify-Filter-AuthZMail
PORTVERSION=	1.01
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Determines Subversion accounts to receive email via the authz file

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-SVN-Access>=0:devel/p5-SVN-Access \
		p5-SVN-Notify>=2.72:devel/p5-SVN-Notify
RUN_DEPENDS=	p5-SVN-Access>=0:devel/p5-SVN-Access \
		p5-SVN-Notify>=2.72:devel/p5-SVN-Notify

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
