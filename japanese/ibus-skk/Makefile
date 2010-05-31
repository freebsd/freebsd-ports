# New ports collection makefile for:	ibus-skk
# Date created:	4 January 2010
# Whom:		Hiroto Kagotani <hiroto.kagotani@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ibus-skk
PORTVERSION=	0.0.4
PORTREVISION=	3
CATEGORIES=	japanese
MASTER_SITES=	http://cloud.github.com/downloads/ueno/ibus-skk/

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	SKK engine for IBus

RUN_DEPENDS=	ibus-daemon:${PORTSDIR}/textproc/ibus \
		${LOCALBASE}/share/skk/SKK-JISYO.L:${PORTSDIR}/japanese/skk-jisyo

USE_PYTHON=	yes
USE_GETTEXT=	yes

USE_GMAKE=	yes
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	DATADIRNAME=share

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.mk>
