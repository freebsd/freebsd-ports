# New ports collection makefile for:   diacanvas
# Date created:        04 February 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	diacanvas
PORTVERSION=	0.40.1
PORTREVISION=	1
CATEGORIES=	graphics gnome
# mastersite disappeared in December 2000
MASTER_SITES=	# http://www.linuxstart.com/~arjan/diacanvas/download/

DEPRECATED=	"master site disappeared, obsoleted by diacanvas2"
EXPIRATION_DATE=2005-08-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general drawing canvas from dia dialog editor

USE_X_PREFIX=	yes
USE_GNOME=	gtk12 imlib gnomehack
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
