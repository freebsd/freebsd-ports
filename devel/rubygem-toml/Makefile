# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	toml
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	TOML parser

LICENSE=	MIT

RUN_DEPENDS=	rubygem-parslet>=1.5:${PORTSDIR}/textproc/rubygem-parslet

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} -e '18 s|~>|">="|' ${WRKSRC}/${GEM_NAME}.gemspec

.include <bsd.port.mk>
