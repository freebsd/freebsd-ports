PORTNAME=	gettext-po-mode
PORTREVISION=	1

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	GNU gettext po-mode for emacs
WWW=		https://www.gnu.org/software/gettext/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/../COPYING

.include "${.CURDIR}/../gettext/Makefile.common"

BUILD_DEPENDS=	libtextstyle>=${PORTVERSION}:devel/libtextstyle
LIB_DEPENDS=	libtextstyle.so:devel/libtextstyle

USES=		cpe emacs tar:xz

CPE_VENDOR=	gnu
CPE_PRODUCT=	gettext

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC_SUBDIR=	gettext-tools

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/emacs/*.el \
	${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
