# New ports collection makefile for:   	deskutils/wamuu-dev
# Date created:        			14 May 2010
# Whom:                			bsam
#
# $FreeBSD$
#

PORTNAME=		wammu
PORTVERSION=		0.33
CATEGORIES=		deskutils
MASTER_SITES=		http://dl.cihar.com/wammu/v0/ \
			http://dl.cihar.com.nyud.net/wammu/v0/

MAINTAINER=		bsam@FreeBSD.org
COMMENT=		GUI program to manage contacts, todos, calendar and messages in your phone

RUN_DEPENDS+=		gammu:${PORTSDIR}/comms/gammu-python

USE_GETTEXT=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
USE_WX=			2.6+
WX_COMPS=		python:run
WX_UNICODE=		yes
USE_GNOME=		pkgconfig

MANLANG=		"" cs de it nl
MAN1=			wammu.1 wammu-configure.1

.include <bsd.port.mk>
