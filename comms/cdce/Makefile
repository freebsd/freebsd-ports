# New ports collection makefile for:	cdce
# Date Created:				Jan 25, 2005
# Whom:					Craig Boston <craig@yekse.gank.org>
#
# $FreeBSD$
#

PORTNAME=	cdce
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.gank.org/freebsd/cdce/

MAINTAINER=	craig@yekse.gank.org
COMMENT=	Driver for point-to-point CDC Ethernet interfaces

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=		"FreeBSD versions prior to 5.3 are not supported"
.endif
NO_PACKAGE=	Depends on kernel

pre-fetch:
.if !exists(${SRC_BASE}/sys/Makefile)
	@${ECHO} "*************************************************"; \
	${ECHO}  "This port requires the kernel source be available"; \
	${ECHO}  "*************************************************"; \
	exit 1
.endif

do-install:
	${MKDIR} ${PREFIX}/lib/cdce
	${INSTALL_SCRIPT} ${WRKSRC}/if_cdce.ko ${PREFIX}/lib/cdce

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
