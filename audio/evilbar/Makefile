# New ports collection makefile for:    evilbar
# Date created:                         31 Januar 2003
# Whom:                                 Jens Arnfast <jens@arnfast.net>
#
# $FreeBSD$
#

PORTNAME=	evilbar
PORTVERSION=	1.2.1
CATEGORIES+=	audio sysutils x11-clocks
MASTER_SITES=	http://arnfast.net/projects/

MAINTAINER=	jens@arnfast.net

GNU_CONFIGURE=	yes

MAN1=		evilbar.1 launch_evilbar.1

.if !defined(WITHOUT_XMMS)
BUILD_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
.else
CONFIGURE_ARGS+=	--disable-xmms
.endif

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if defined(WITH_APM)
CONFIGURE_ARGS+=	--enable-apm
.endif

pre-everything:
.if !defined(WITHOUT_XMMS)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can disable XMMS control by defining WITHOUT_XMMS."
.endif
.if !defined(WITH_APM)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable APM status by defining WITH_APM."
.endif
	@${ECHO_MSG}

.include <bsd.port.mk>
