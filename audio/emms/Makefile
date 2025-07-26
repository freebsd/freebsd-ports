PORTNAME=	emms
DISTVERSION=	23
CATEGORIES=	audio elisp
MASTER_SITES=	https://elpa.gnu.org/packages/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	GNU/Emacs Multimedia System
WWW=		https://www.gnu.org/software/emms/ \
		https://elpa.gnu.org/packages/emms.html \
		https://git.savannah.gnu.org/cgit/emms.git/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

# do not depend on base texinfo on 10
BUILD_DEPENDS=	texi2dvi:print/texinfo

USES=		emacs gmake tar

CONFLICTS_INSTALL=	emms emms-emacs_* # share/emacs/site-lisp/emms/emms-auto.el

NO_ARCH=	yes

INFO=		emms

.include <bsd.port.mk>
