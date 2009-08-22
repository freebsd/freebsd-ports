# New ports collection makefile for:	gourmet
# Date created:				14 April, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gourmet
PORTVERSION=	0.13.4
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/grecipe-manager/grecipe-manager/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-2

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	GNOME recipe manager

LIB_DEPENDS=	mk4:${PORTSDIR}/databases/metakit
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite21 \
		${PYTHON_SITELIBDIR}/PyRTF/__init__.py:${PORTSDIR}/print/py-rtf \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GETTEXT=yes

USE_GNOME=	pygnome2

.include <bsd.port.mk>
