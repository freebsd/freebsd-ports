# Ports collection makefile for: Japanese Font Setup for Netscape browsers
# Version required:	1.0
# Date created:		22 Jun 1998
# Whom:                 sada
#
# $Id: Makefile,v 1.5 1998/11/23 08:16:09 asami Exp $
#

DISTNAME=	ja-netscape-fonts-1.0
CATEGORIES=	japanese www x11-fonts
DISTFILES=	# empty

MAINTAINER=	sada@freebsd.org

RUN_DEPENDS= \
	${PREFIX}/lib/X11/fonts/local/jpnhn4-iso.pcf.gz:${PORTSDIR}/japanese/elisa8x8 \
	${PREFIX}/lib/X11/fonts/local/5x10B.pcf.gz:${PORTSDIR}/japanese/k10 \
	${PREFIX}/lib/X11/fonts/local/knmhn12x.pcf.gz:${PORTSDIR}/japanese/k12 \
	${PREFIX}/lib/X11/fonts/local/k20b.pcf.gz:${PORTSDIR}/japanese/kappa20

USE_X_PREFIX=	yes
NO_BUILD=	yes

do-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		/usr/bin/perl ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
