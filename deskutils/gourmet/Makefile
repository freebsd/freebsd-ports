# New ports collection makefile for:	gourmet
# Date created:				14 April, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gourmet
PORTVERSION=	0.11.2
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/grecipe-manager

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	GNOME recipe manager

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite21 \
		${PYTHON_SITELIBDIR}/PyRTF/__init__.py:${PORTSDIR}/print/py-rtf \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

USE_GNOME=	pygnome2

.include <bsd.port.mk>
