# Created by: dom@happygiraffe.net
# $FreeBSD$

PORTNAME=	SVN-Notify
PORTVERSION=	2.86
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Subversion activity notification

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Email-Address>=1.89.7:mail/p5-Email-Address \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-Net-SMTP-TLS>=0:mail/p5-Net-SMTP-TLS \
		p5-Text-Trac>=0.10:textproc/p5-Text-Trac
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
