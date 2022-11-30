PORTNAME=	emms
DISTVERSION=	5.0
PORTREVISION=	10
CATEGORIES=	audio elisp
MASTER_SITES=	GNU
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs Multi-Media System
WWW=		https://www.gnu.org/software/emms/index.html

LICENSE=	GPLv3

# do not depend on base texinfo on 10
BUILD_DEPENDS=	texi2dvi:print/texinfo

USES=		emacs gmake

CONFLICTS_INSTALL=	emms emms-emacs_* # share/emacs/site-lisp/emms/emms-auto.el

INFO=		emms
NO_ARCH=	yes

.include <bsd.port.mk>
