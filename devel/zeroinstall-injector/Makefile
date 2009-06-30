# New ports collection makefile for:    zeroinstall-injector
# Date created:         2007-06-24
# Whom:                 Dylan Cochran <a134qaed@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	zeroinstall-injector
PORTVERSION=	0.41
CATEGORIES=	devel python
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=zero-install

MAINTAINER=	a134qaed@gmail.com
COMMENT=	0install injector

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/_gtk.so:${PORTSDIR}/x11-toolkits/py-gtk2 \
				${PYTHON_SITELIBDIR}/gtk-2.0/gobject/_gobject.so:${PORTSDIR}/devel/py-gobject \
				gpg:${PORTSDIR}/security/gnupg \
				lzma:${PORTSDIR}/archivers/lzma

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PLIST_SUB=	PYTHON_VER=${PYTHON_VER}

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

MAN1=		0launch.1 0alias.1 0store.1 0store-secure-add.1 0desktop.1

.include <bsd.port.mk>
