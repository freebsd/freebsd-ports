# ex:ts=8
# New ports collection makefile for:	emirror
# Date created:			Apr 19, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	emirror
PORTVERSION=	2.1.21
PORTREVISION=	2
CATEGORIES=	ftp python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://eclipt.uni-klu.ac.at/pub/projects/emirror/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full features FTP-mirroring software with nice logfiles

USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc
USE_GMAKE=	yes
NO_BUILD=	yes

MAN1=	emirror.1

.include <bsd.port.mk>
