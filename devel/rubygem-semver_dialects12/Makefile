PORTNAME=	semver_dialects
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	12

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse, process and compare semantic versions
WWW=		https://gitlab.com/gitlab-org/vulnerability-research/foss/semver_dialects

LICENSE=	MIT

RUN_DEPENDS=	rubygem-pastel>=0.8.0<0.9:devel/rubygem-pastel \
		rubygem-thor12>=1.2.0<1.3:devel/rubygem-thor12 \
		rubygem-tty-command>=0.10.1<0.11:devel/rubygem-tty-command

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.2\.

.include <bsd.port.mk>
