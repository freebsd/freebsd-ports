# Ports collection makefile for: Japanese Font Setup for Netscape browsers
# Version required:	1.0
# Date created:		22 Jun 1998
# Whom:                 sada
#
# $Id$
#

DISTNAME=	ja-netscape-fonts-1.0
CATEGORIES=	japanese www x11-fonts
DISTFILES=	# empty

MAINTAINER=	sada@e-mail.ne.jp

RUN_DEPENDS= \
	${PREFIX}/lib/X11/k12:${PORTSDIR}/japanese/k12 \
	${PREFIX}/lib/X11/fonts/misc/5x10B.pcf.Z:${PORTSDIR}/japanese/k10

USE_X_PREFIX=	yes
NO_BUILD=	yes

do-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		/usr/bin/perl ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
