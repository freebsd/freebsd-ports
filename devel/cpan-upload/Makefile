PORTNAME=	cpan-upload
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NEILB/scripts

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Script for uploading distributions to CPAN

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-AppConfig-Std>=1.05:devel/p5-AppConfig-Std \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

CONFLICTS_INSTALL=	p5-CPAN-Uploader

.include <bsd.port.mk>
