# New ports collection makefile for:	mcomix
# Date created:		2012-05-16
# Whom:			Ashish SHUKLA <ashish@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mcomix
PORTVERSION=	0.99
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/MComix-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	A GTK2 comic book viewer

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=		yes
USE_GNOME=		pygtk2
USE_PYTHON=		2.6+
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
