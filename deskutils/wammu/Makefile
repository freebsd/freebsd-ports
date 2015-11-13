# Created by: bsam
# $FreeBSD$

PORTNAME=	wammu
PORTVERSION=	0.36
PORTREVISION=	8
CATEGORIES=	deskutils
MASTER_SITES=	http://dl.cihar.com/wammu/v0/ \
		http://dl.cihar.com.nyud.net/wammu/v0/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI manager of contacts, todos, calendar, and messages in your phone

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libGammu.so:${PORTSDIR}/comms/gammu

USES=		gettext pkgconfig python tar:bz2
USE_PYTHON=	distutils
USE_WX=		3.0+
WX_COMPS=	python:lib
NO_ARCH=	yes

.include <bsd.port.mk>
