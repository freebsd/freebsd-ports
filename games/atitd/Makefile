# New ports collection makefile for:	atitd
# Date created:         17 Jul 2003
# Whom:                 Matthew N. Dodd <mdodd@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	atitd
PORTVERSION=	1.0
CATEGORIES=	games graphics linux
MASTER_SITES=	http://www.atitd.com/
DISTNAME=	eClient-linux.run
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	mdodd@freebsd.org
COMMENT=	The Linux "A Tale in the Desert" (ATITD) client

RUN_DEPENDS=	${X11BASE}/bin/xhost:${X_CLIENTS_PORT}

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-3
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri
.else
RUN_DEPENDS+=	${LINUXBASE}/lib/libGL.so:${PORTSDIR}/graphics/linux_glx
.endif

PLIST_FILES=	bin/atitd
USE_LINUX=	yes
USE_MESA=	yes

ONLY_FOR_ARCHS=	i386
NO_CDROM=	"Redistribution not allowed"
NO_PACKAGE=	"Not packagable."
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

LINUX_SH=	${LINUXBASE}/bin/sh
ECLIENT=	${DISTDIR}/${DISTFILES}

checksum:
	@${LINUX_SH} ${ECLIENT} --check

post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/atitd.sh > ${WRKSRC}/atitd.sh

pre-install:
	@${ECHO_MSG} "===>  Running the pre-install script."
	@PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PORTNAME} PRE-INSTALL

do-install:
	@${LINUX_SH} ${ECLIENT} --nox11 --nochown \
				--target ${PREFIX}/games/atitd
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}

post-install:
	@${ECHO_MSG} "===>  Fixing permissions."
	@${CHOWN} -R atitd:atitd ${PREFIX}/games/atitd
	@${CHMOD} ug+s ${PREFIX}/games/atitd/elaunch
	${INSTALL_SCRIPT} ${WRKSRC}/atitd.sh ${PREFIX}/bin/atitd
	@${ECHO_MSG} "===>  Running the post-install script."
	@PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PORTNAME} POST-INSTALL

.include <bsd.port.post.mk>
