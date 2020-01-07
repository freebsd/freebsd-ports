# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	emms
DISTVERSION=	5.0
PORTREVISION=	3
CATEGORIES=	audio elisp
MASTER_SITES=	GNU
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs Multi-Media System

LICENSE=	GPLv3

# do not depend on base texinfo on 10
BUILD_DEPENDS=	texi2dvi:print/texinfo

USES=		emacs gmake

INFO=		emms
NO_ARCH=	yes

.include <bsd.port.mk>
