# New ports collection makefile for:	linux-js
# Date created:				5 Feb 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linux-js
PORTVERSION=	2.0
CATEGORIES=	devel emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jylefort

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	The Linux joystick interface ported to FreeBSD

PROGRAMS=	jscal jstest

MAN1=		${PROGRAMS:S|$|.1|}
MAN4=		linux_js.4
PORTDOCS=	joystick-api.txt
USE_RCORDER=	jscal.sh linux_js.sh

OPTIONS=	JOY "PC joystick support" on \
		UHID "USB joystick support" on

MAKE_ENV=	WITHOUT_DEBUG=yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503001
IGNORE=		requires FreeBSD 5.3 or superior
.endif

.if !exists(/usr/src/sys/Makefile)
IGNORE=		requires kernel source files
.endif

.if defined(WITHOUT_JOY)
MAKE_ENV+=	WITHOUT_JOY=yes
.endif

.if defined(WITHOUT_UHID)
MAKE_ENV+=	WITHOUT_UHID=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/linux_js.4

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
