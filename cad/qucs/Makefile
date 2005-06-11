# New ports collection makefile for:	qucs
# Date created:				2005-06-11
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	qucs
PORTVERSION=	0.0.6
CATEGORIES=	cad science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	des@FreeBSD.org
COMMENT=	Graphical circuit design and simulation tool

USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=""

MAN1=		qucs.1 qucsator.1 qucsconv.1 qucsedit.1 \
		qucsfilter.1 qucshelp.1 qucstrans.1

.include <bsd.port.mk>
