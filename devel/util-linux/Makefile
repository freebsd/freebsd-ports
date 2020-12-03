# $FreeBSD$

PORTNAME=	util-linux
DISTVERSION=	2.36
CATEGORIES=	devel
MASTER_SITES=	KERNEL_ORG/linux/utils/util-linux/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Random collection of Linux utilities

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf gettext-tools gmake libtool ncurses pkgconfig \
		shebangfix tar:xz
USE_LDCONFIG=	yes

SHEBANG_FILES=	misc-utils/getopt-parse.bash

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls --disable-ipcrm --disable-ipcs \
		--disable-makeinstall-chown --disable-makeinstall-setuid

INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	cal

OPTIONS_DEFINE=		UUID
OPTIONS_SUB=		yes

UUID_DESC=		Install libuuid
UUID_CONFIGURE_ENABLE=	libuuid

post-install: # https://github.com/karelzak/util-linux/issues/1149
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
