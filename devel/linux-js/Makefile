# New ports collection makefile for:	linux-js
# Date created:				5 Feb 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linux-js
PORTVERSION=	2.2
CATEGORIES=	devel emulators kld
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jylefort

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Linux joystick interface ported to FreeBSD

PROGRAMS=	jscal jstest

MAN1=		${PROGRAMS:S|$|.1|}
MAN4=		linux_js.4
PORTDOCS=	joystick-api.txt
USE_RC_SUBR=	jscal linux_js

OPTIONS_DEFINE=	LINUX JOY UHID DOCS
OPTIONS_DEFAULT=	LINUX JOY UHID

LINUX_DESC=	Linux mode support (i386/amd64 only)
JOY_DESC=	PC joystick support
UHID_DESC=	USB joystick support

MAKE_ENV=	WITHOUT_DEBUG=yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800064
BROKEN=	does not build
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source files
.endif

.if empty(PORT_OPTIONS:MLINUX)
MAKE_ENV+=	WITHOUT_LINUX=yes
.endif

.if empty(PORT_OPTIONS:MJOY)
MAKE_ENV+=	WITHOUT_JOY=yes
.endif

.if empty(PORT_OPTIONS:MUHID)
MAKE_ENV+=	WITHOUT_UHID=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/linux_js.4
	@${REINPLACE_CMD} -e 's|FILEDESC_UNLOCK|FILEDESC_SUNLOCK|' ${WRKSRC}/linux_js.c
	@${REINPLACE_CMD} -e 's|FILEDESC_LOCK|FILEDESC_SLOCK|' ${WRKSRC}/linux_js.c

post-install:
	${MKDIR} ${PREFIX}/include/linux
	${INSTALL_DATA} ${WRKSRC}/joystick.h ${PREFIX}/include/linux
	${INSTALL_PROGRAM} ${PROGRAMS:S|^|${WRKSRC}/|} ${PREFIX}/bin
.for s in 1 4
	${INSTALL_MAN} ${MAN${s}:S|^|${WRKSRC}/|} ${PREFIX}/man/man${s}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/joystick-api.txt ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
