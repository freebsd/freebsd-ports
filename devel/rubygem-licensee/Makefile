# Created by: Brendan Molloy <brendan+freebsd@bbqsrc.net>
# $FreeBSD$

PORTNAME=	licensee
PORTVERSION=	9.14.1
PORTREVISION=	0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Detects under what license a project is distributed

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-dotenv>=2.0<3:misc/rubygem-dotenv \
		rubygem-octokit>=4.17<5:net/rubygem-octokit \
		rubygem-reverse_markdown>=1.0<2:textproc/rubygem-reverse_markdown \
		rubygem-rugged>=0.24<2.0:devel/rubygem-rugged \
		rubygem-thor>=0.19<2.0:devel/rubygem-thor

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/licensee

.include <bsd.port.mk>
