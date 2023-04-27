PORTNAME=	spacefm
DISTVERSION=	1.0.6
PORTREVISION=	3
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SpaceFM file manager
WWW=		https://ignorantguru.github.io/spacefm

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash # for configure
LIB_DEPENDS=	libffmpegthumbnailer.so:multimedia/ffmpegthumbnailer \
		libinotify.so:devel/libinotify \
		libstartup-notification-1.so:x11/startup-notification \
		libudev.so:devel/libudev-devd
RUN_DEPENDS=	bash:shells/bash

USES=		desktop-file-utils gettext gmake gnome localbase:ldflags \
		pkgconfig shared-mime-info shebangfix xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20 intltool pango
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	IgnorantGuru

SHEBANG_FILES=	src/spacefm-auth.bash spacefm-installer

GNU_CONFIGURE=	yes
CONFIGURE_SHELL=	${PREFIX}/bin/bash
CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc \
		--with-bash-path=${LOCALBASE}/bin/bash

CFLAGS+=	-Dstat64=stat -Dfstat64=fstat -Dlstat64=lstat \
		-fcommon
LDFLAGS+=	-lX11 -linotify

OPTIONS_DEFINE=		DOCS
OPTIONS_GROUP=		OPT_DEPS
OPTIONS_GROUP_OPT_DEPS=	CURLFTPFS IFUSE JMTPFS LSOF PHOTOFS

PORTDOCS=	*

CURLFTPFS_DESC=		Mount FTP shares
CURLFTPFS_RUN_DEPENDS=	fusefs-curlftpfs>0:sysutils/fusefs-curlftpfs

IFUSE_DESC=		Mount your iPhone/iPod Touch
IFUSE_RUN_DEPENDS=	fusefs-ifuse>0:sysutils/fusefs-ifuse

JMTPFS_DESC=		Mount MTP devices
JMTPFS_RUN_DEPENDS=	fusefs-jmtpfs>0:sysutils/fusefs-jmtpfs

LSOF_DESC=		Device processes
LSOF_RUN_DEPENDS=	lsof:sysutils/lsof

PHOTOFS_DESC=		Mount cameras
PHOTOFS_RUN_DEPENDS=	fusefs-gphotofs>0:graphics/fusefs-gphotofs

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|' \
		${WRKSRC}/src/ptk/ptk-handler.c
	@${REINPLACE_CMD} -e '\
		s|^/bin/bash|${LOCALBASE}/bin/bash|; \
		s|/usr/bin/sha256sum|/sbin/sha256| \
		' \
		${WRKSRC}/src/spacefm-auth.bash

.include <bsd.port.mk>
