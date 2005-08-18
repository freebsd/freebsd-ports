# New ports collection makefile for:	gourmet
# Date created:				14 April, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gourmet
PORTVERSION=	0.8.5.7
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	grecipe-manager

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	GNOME recipe manager

RUN_DEPENDS=	${LOCALBASE}/lib/libmk4py.so:${PORTSDIR}/databases/metakit \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

# This is only for during the ports freeze for 6.0-RELEASE. gourmet
# requires a python-aware metakit, and that cannot be specified with
# the current metakit framework.
IGNORE=		The python-aware metakit requirement cannot be fulfilled with the current ports framework

USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

USE_GNOME=	pygnome2

.include <bsd.port.pre.mk>

pre-install:
.if !exists(${LOCALBASE}/lib/libmk4py.so)
.if exists(${LOCALBASE}/lib/libmk4.so)
BROKEN=	"You must reinstall metakit to include python support (define METAKIT_WITH_PYTHON=yes when building metakit)"
.endif
.endif

.include <bsd.port.post.mk>
