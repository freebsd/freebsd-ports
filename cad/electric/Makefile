# New ports collection makefile for:	electric
# Date created:		4 May 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	electric
PORTVERSION=	5.7.4
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org

USE_XLIB=	yes
USE_MOTIF=	yes
EXTRA_PATCHES=	${WRKDIR}/patch-prefix
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ENV+=	X11BASE="${X11BASE}" HACK_INSTALL_DIR="${INSTALL_DIR}"

INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755

pre-patch:
	${SED} "s!PREFIX!${PREFIX}!g" ${FILESDIR}/template-patch-prefix > ${EXTRA_PATCHES}

.include <bsd.port.mk>
