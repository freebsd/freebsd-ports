# New ports collection makefile for:	linux-js
# Date created:				5 Feb 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linux-js
PORTVERSION=	1.0
CATEGORIES=	devel emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jylefort

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	The Linux joystick interface ported to FreeBSD

PROGRAMS=	jscal jstest

MAN1=		${PROGRAMS:S|$|.1|}
PORTDOCS=	joystick-api.txt
USE_RC_SUBR=	jscal.sh

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503001
IGNORE=		requires FreeBSD 5.3 or superior
.endif

.if !exists(/usr/src/sys/Makefile)
IGNORE=		requires kernel source files
.endif

post-install:
	${MKDIR} ${PREFIX}/include/linux
	${INSTALL_DATA} ${WRKSRC}/joystick.h ${PREFIX}/include/linux
	${INSTALL_PROGRAM} ${PROGRAMS:S|^|${WRKSRC}/|} ${PREFIX}/bin
	${INSTALL_MAN} ${MAN1:S|^|${WRKSRC}/|} ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/joystick-api.txt ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
