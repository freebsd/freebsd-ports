# Created by: bsam
# $FreeBSD$

PORTNAME=		wammu
PORTVERSION=		0.36
PORTREVISION=		3
CATEGORIES=		deskutils
MASTER_SITES=		http://dl.cihar.com/wammu/v0/ \
			http://dl.cihar.com.nyud.net/wammu/v0/

MAINTAINER=		bsam@FreeBSD.org
COMMENT=		GUI program to manage contacts, todos, calendar, and messages in your phone

LICENSE=		GPLv2

BUILD_DEPENDS+=		gammu:${PORTSDIR}/comms/gammu
RUN_DEPENDS+=		gammu:${PORTSDIR}/comms/gammu

USES=			gettext pkgconfig
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
USE_WX=			2.6+
WX_COMPS=		python:lib
WX_UNICODE=		yes

MANLANG=		"" cs de it nl pt_BR
MAN1=			wammu.1 wammu-configure.1

.include <bsd.port.mk>
