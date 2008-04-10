# New ports collection makefile for:	pypersrc
# Date created:		18 Apr 2006
# Whom:			Joseph Koshy <jkoshy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pypersrc
PORTVERSION=	20060325
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.jimbrooks.org/pypersrc/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkoshy
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python/Tkinter based source browser

BUILD_DEPENDS=	exctags:${PORTSDIR}/devel/ctags \
		${PYTHON_SITELIBDIR}/Pmw:${PORTSDIR}/x11-toolkits/py-Pmw
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_PYTHON=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh

.include <bsd.port.mk>
