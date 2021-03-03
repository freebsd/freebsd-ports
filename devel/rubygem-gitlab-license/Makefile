# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-license
PORTVERSION=	1.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Generate, verify and enforce software licenses

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	bash>0:shells/bash

USES=		gem shebangfix
USE_RUBY=	yes
SHEBANG_FILES=	bin/setup

NO_ARCH=	yes

.include <bsd.port.mk>
