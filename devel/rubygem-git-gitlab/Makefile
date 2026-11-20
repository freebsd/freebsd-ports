PORTNAME=	git
PORTVERSION=	5.7.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby wrapper library around git(1)
WWW=		https://github.com/ruby-git/ruby-git

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git>=1.6:devel/git \
		rubygem-activesupport-gitlab>=5.0:devel/rubygem-activesupport-gitlab \
		rubygem-addressable>=2.8<3:www/rubygem-addressable \
		rubygem-process_executer>=4.1<5:devel/rubygem-process_executer \
		rubygem-rchardet>=1.9<2:textproc/rubygem-rchardet

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
