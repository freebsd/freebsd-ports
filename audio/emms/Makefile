PORTNAME=	emms
DISTVERSION=	20.1
CATEGORIES=	audio elisp
MASTER_SITES=	https://elpa.gnu.org/packages/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}
EXTRACT_SUFX=	.tar

MAINTAINER=	alster@vinterdalen.se
COMMENT=	Emacs Multi-Media System
WWW=		https://www.gnu.org/software/emms/index.html

LICENSE=	GPLv3

# do not depend on base texinfo on 10
BUILD_DEPENDS=	texi2dvi:print/texinfo

USES=		emacs gmake

CONFLICTS_INSTALL=	emms emms-emacs_* # share/emacs/site-lisp/emms/emms-auto.el

NO_ARCH=	yes

INFO=		emms

.include <bsd.port.mk>
