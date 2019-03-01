# Created by: Jacob Atzen <jatzen@gmail.com>
# $FreeBSD$

PORTNAME=	daemon_controller
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMEPREFIX=	rubygem-

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Library for implementing daemon management capabilities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gem shebangfix

NO_ARCH=	yes

USE_RUBY=	yes
SHEBANG_FILES=	rpm/get_distro_id.py \
		debian.template/rules

.include <bsd.port.mk>
