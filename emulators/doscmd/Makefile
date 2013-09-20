# $FreeBSD$

PORTNAME=	doscmd
PORTVERSION=	20110826
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	doscmd

MAINTAINER=	shurd@sasktel.net
COMMENT=	DOS emulator

ONLY_FOR_ARCHS=	i386
.ifdef WITHOUT_X11
MAKE_ARGS+=	-DNO_X
PLIST_SUB+=	X11="@comment "
.else
USE_XORG=	x11
PLIST_SUB+=	X11=""
MAKE_ARGS+=	X11BASE=${LOCALBASE}
.endif
MAKE_ARGS+=	MANDIR="${PREFIX}/man/man"
MAN1=		doscmd.1
MANCOMPRESSED=	yes

NO_STAGE=	yes
post-install:
	@${ECHO_MSG} NOTE:
	@${ECHO_MSG} =====
	@${ECHO_MSG} For security reasons, FreeBSD no longer allows mmap\(\) at zero.
	@${ECHO_MSG} To remove this security protection and allow doscmd to work, you will need
	@${ECHO_MSG} to set sysctl security.bsd.map_at_zero=1 either before running doscmd or
	@${ECHO_MSG} in /etc/sysctl.conf.

.include <bsd.port.mk>
