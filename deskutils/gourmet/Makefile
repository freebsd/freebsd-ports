# New ports collection makefile for:	gourmet
# Date created:				14 April, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gourmet
PORTVERSION=	0.9.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	grecipe-manager

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	GNOME recipe manager

RUN_DEPENDS=	${LOCALBASE}/lib/libmk4py.so:${PORTSDIR}/databases/metakit \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

BROKEN=		Incomplete pkg-plist

USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

USE_GNOME=	pygnome2

post-install:
.if exists(${PYTHON_SITELIBDIR}/metakit.pyc)
	@${CHMOD} 0555 ${PYTHON_SITELIBDIR}/metakit.pyc
.endif

.include <bsd.port.mk>
