PORTNAME=	util-linux
DISTVERSION=	2.39.4
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	KERNEL_ORG/linux/utils/util-linux/v${DISTVERSION:R}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Random collection of Linux utilities
WWW=		https://github.com/util-linux/util-linux

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libuuid.so:misc/libuuid
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf gettext-tools gmake libtool ncurses pkgconfig \
		shebangfix tar:xz

USE_LDCONFIG=	yes

SHEBANG_FILES=	misc-utils/getopt-example.bash \
		tools/*.sh \
		tools/git-tp-sync \
		tools/git-tp-sync-man \
		tests/run.sh

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--disable-nls --disable-ipcrm --disable-ipcs \
		--disable-makeinstall-chown --disable-makeinstall-setuid \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

INSTALL_TARGET=	install-strip
TEST_TARGET=	check # tests fail due to https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=273196

CONFLICTS_INSTALL=	heirloom-doctools

OPTIONS_DEFINE=		CAL FLOCK GETOPT HARDLINK UUID
OPTIONS_DEFAULT=	GETOPT
OPTIONS_SUB=		yes

CAL_DESC=		Install util-linux cal(1)
CAL_CONFIGURE_ENABLE=	cal

FLOCK_DESC=		Install util-linux flock(1)
FLOCK_CONFIGURE_ENABLE=	flock

GETOPT_DESC=		Install util-linux getopt(1)
GETOPT_CONFIGURE_ENABLE=getopt

HARDLINK_DESC=		Install util-linux hardlink(1)
HARDLINK_CONFIGURE_ENABLE=hardlink

UUID_DESC=		Install libuuid
UUID_CONFIGURE_ENABLE=	libuuid

post-install: # https://github.com/karelzak/util-linux/issues/1149
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
