# Created by: bsam
# $FreeBSD$

PORTNAME=		wammu
PORTVERSION=		0.36
PORTREVISION=	6
CATEGORIES=		deskutils
MASTER_SITES=		http://dl.cihar.com/wammu/v0/ \
			http://dl.cihar.com.nyud.net/wammu/v0/

MAINTAINER=		bsam@FreeBSD.org
COMMENT=		GUI manager of contacts, todos, calendar, and messages in your phone

LICENSE=		GPLv2

LIB_DEPENDS+=		libGammu.so:${PORTSDIR}/comms/gammu

USES=			gettext pkgconfig
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
USE_WX=			2.6+
WX_COMPS=		python:lib
WX_UNICODE=		yes

.include <bsd.port.mk>
