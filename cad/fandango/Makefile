# ex:ts=8
# Ports collection makefile for:	fandango
# Date created:			Feb 17, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fandango
PORTVERSION=	0.2.5
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	elcad
DISTNAME=	k${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A python scripted 3D CAD application

LIB_DEPENDS=	python2.3.1:${PORTSDIR}/lang/python

USE_GL=		yes
USE_GNOME=	gnometarget
USE_KDEBASE_VER=	3
USE_PYTHON=	2.3+
GNU_CONFIGURE=	yes

pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} "***    This port requires python shared library    ***"
	@${ECHO_CMD} "*** You have to build python with BUILD_SHARED=yes ***"
	@${ECHO_CMD}

.include <bsd.port.mk>
