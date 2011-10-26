# New ports collection makefile for:    zeroinstall-injector
# Date created:         2007-06-24
# Whom:                 Dylan Cochran <a134qaed@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	zeroinstall-injector
PORTVERSION=	1.4.1
CATEGORIES=	devel python
MASTER_SITES=	SF/zero-install/injector/${PORTVERSION}

MAINTAINER=	a134qaed@gmail.com
COMMENT=	0install injector

RUN_DEPENDS=	gpg2:${PORTSDIR}/security/gnupg \
		xdg-utils>=0:${PORTSDIR}/devel/xdg-utils

USE_BZIP2=	yes
USE_GNOME=	pygtk2 pygobject
USE_PYTHON=	2.6+
USE_PYDISTUTILS=	yes
INSTALLS_ICONS=	yes

MAN1=		0alias.1 0desktop.1 0install.1 0launch.1 0store-secure-add.1 0store.1

DEPRECATED=	Duplicates PBI functionality, and 0install feeds are available as ports
EXPIRATION_DATE=2011-12-01

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505
RUN_DEPENDS+=	unlzma:${PORTSDIR}/archivers/xz
.endif

.include <bsd.port.post.mk>
