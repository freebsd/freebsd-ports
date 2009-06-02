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
USE_RCORDER=	jscal.sh linux_js.sh

OPTIONS=	LINUX "Linux mode support (i386/amd64 only)" on \
		JOY "PC joystick support" on \
		UHID "USB joystick support" on

MAKE_ENV=	WITHOUT_DEBUG=yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800064
BROKEN=	does not build
.endif

.if !exists(/usr/src/sys/Makefile)
IGNORE=		requires kernel source files
.endif

.if defined(WITHOUT_LINUX)
MAKE_ENV+=	WITHOUT_LINUX=yes
.endif

.if defined(WITHOUT_JOY)
MAKE_ENV+=	WITHOUT_JOY=yes
.endif

.if defined(WITHOUT_UHID)
MAKE_ENV+=	WITHOUT_UHID=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/linux_js.4
.if ${OSVERSION} >= 700000
	@${REINPLACE_CMD} -e 's|FILEDESC_UNLOCK|FILEDESC_SUNLOCK|' ${WRKSRC}/linux_js.c
	@${REINPLACE_CMD} -e 's|FILEDESC_LOCK|FILEDESC_SLOCK|' ${WRKSRC}/linux_js.c
.endif

post-install:
	${MKDIR} ${PREFIX}/include/linux
	${INSTALL_DATA} ${WRKSRC}/joystick.h ${PREFIX}/include/linux
	${INSTALL_PROGRAM} ${PROGRAMS:S|^|${WRKSRC}/|} ${PREFIX}/bin
.for s in 1 4
	${INSTALL_MAN} ${MAN${s}:S|^|${WRKSRC}/|} ${PREFIX}/man/man${s}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/joystick-api.txt ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
