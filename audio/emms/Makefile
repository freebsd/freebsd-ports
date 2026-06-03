PORTNAME=	emms
DISTVERSION=	26
CATEGORIES=	audio elisp
MASTER_SITES=	https://elpa.gnu.org/packages/

MAINTAINER=	alven@FreeBSD.org
COMMENT=	GNU/Emacs Multimedia System
WWW=		https://www.gnu.org/software/emms/ \
		https://elpa.gnu.org/packages/emms.html \
		https://cgit.git.savannah.gnu.org/cgit/emms.git/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

# do not depend on base texinfo on 10
BUILD_DEPENDS=	texi2dvi:print/texinfo

USES=		emacs:build gmake tar

CONFLICTS_INSTALL=	emms-emacs_*

NO_ARCH=	yes

INFO=		emms

do-build:
	${GMAKE} -C ${WRKSRC} emms-auto.el docs

.include <bsd.port.mk>
