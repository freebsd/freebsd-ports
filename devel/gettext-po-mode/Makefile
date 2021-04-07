PORTNAME=	gettext-po-mode
PORTREVISION=	1

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	GNU gettext po-mode for emacs

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/../COPYING

.include "${.CURDIR}/../gettext/Makefile.common"

BUILD_DEPENDS=	libtextstyle>=${PORTVERSION}:devel/libtextstyle
LIB_DEPENDS=	libtextstyle.so:devel/libtextstyle

USES=		cpe emacs:build tar:xz

CPE_VENDOR=	gnu
CPE_PRODUCT=	gettext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs --without-git ac_cv_lib_rt_sched_yield=no
INSTALL_TARGET=	install

BUILD_WRKSRC=	${WRKSRC}/emacs
INSTALL_WRKSRC=	${BUILD_WRKSRC}
WRKSRC_SUBDIR=	gettext-tools

PLIST_SUB=	PORTVERSION=${PORTVERSION} VERSION=${PORTVERSION}

.include <bsd.port.mk>
