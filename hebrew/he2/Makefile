# New ports collection makefile for:	he2
# Date created:				3 August 2001
# Whom:					nadav@libagent.org
#
# $FreeBSD$
#

PORTNAME=	he2
PORTVERSION=	0.61
PORTREVISION=	2
CATEGORIES=	hebrew editors
MASTER_SITES=	SF/${PORTNAME}/HebrewEditor/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An editor for editing (primarily LaTeX) Hebrew files

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/hebrew:${PORTSDIR}/hebrew/elmar-fonts

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu`

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
