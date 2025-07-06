PORTNAME=	util-linux
DISTVERSION=	2.39.4
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	KERNEL_ORG/linux/utils/util-linux/v${DISTVERSION:R}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Random collection of Linux utilities
WWW=		https://github.com/util-linux/util-linux

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libblkid.so:filesystems/libblkid \
		libuuid.so:misc/libuuid
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

OPTIONS_DEFINE=		CAL FLOCK GETOPT HARDLINK
OPTIONS_DEFAULT=	GETOPT
OPTIONS_SUB=		yes

CAL_DESC=		Install util-linux cal(1)
CAL_CONFIGURE_ENABLE=	cal

FLOCK_DESC=		Install util-linux flock(1)
FLOCK_RUN_DEPENDS=	flock>=2:sysutils/flock

GETOPT_DESC=		Install util-linux getopt(1)
GETOPT_RUN_DEPENDS=	getopt>=1:misc/getopt

HARDLINK_DESC=		Install util-linux hardlink(1)
HARDLINK_CONFIGURE_ENABLE=hardlink

post-install: # https://github.com/karelzak/util-linux/issues/1149
	${RM} -r ${STAGEDIR}${DOCSDIR}
	${RM} -r ${STAGEDIR}${PREFIX}/include/blkid/
	${RM} ${STAGEDIR}${PREFIX}/share/man/man5/terminal-colors.d.5*
	${FIND} ${STAGEDIR}${PREFIX} -name 'flock*' -delete
	${FIND} ${STAGEDIR}${PREFIX} -name 'getopt*' -delete
	${FIND} ${STAGEDIR}${PREFIX} -name 'blkid*' -delete
	${FIND} ${STAGEDIR}${PREFIX} -name 'libblkid*' -delete
	${FIND} ${STAGEDIR}${PREFIX} -name 'libuuid*' -delete
	${FIND} ${STAGEDIR}${PREFIX} -name 'uuid*' -delete

.include <bsd.port.mk>
