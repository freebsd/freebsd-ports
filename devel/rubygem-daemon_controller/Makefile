# Created by: Jacob Atzen <jatzen@gmail.com>
# $FreeBSD$

PORTNAME=	daemon_controller
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Library for implementing daemon management capabilities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gem python:env shebangfix
USE_RUBY=	yes

SHEBANG_FILES=	rpm/get_distro_id.py

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e '1d' ${WRKSRC}/debian.template/rules

.include <bsd.port.mk>
