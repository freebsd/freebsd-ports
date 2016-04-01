# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Tangram
PORTVERSION=	2.12
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Orthogonal Object Persistence in Relational Databases

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-Class-Date>=0:devel/p5-Class-Date \
		p5-DBI>=0:databases/p5-DBI \
		p5-Data-Lazy>=0.6:devel/p5-Data-Lazy \
		p5-Set-Object>=1.1:devel/p5-Set-Object
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
