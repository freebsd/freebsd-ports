# New ports collection makefile for:    hanIM
# Date created:         17 Mar 1998
# Whom:                 CHOI Junho <cjh@kr.freebsd.org
#
# $FreeBSD$
#

PORTNAME=	hanIM
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	korean x11
MASTER_SITES=   ftp://ftp.mizi.com/pub/hanIM/

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Mizi Research's Korean X11 Input Method

RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/local/gulim12.pcf.gz:${PORTSDIR}/korean/baekmukfonts-bdf

USE_IMAKE=	YES
USE_XPM=	yes
WRKSRC=		${WRKDIR}/hanIM

post-install:
	${MKDIR} ${PREFIX}/share/doc/hanIM
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/LICENSE \
			${PREFIX}/share/doc/hanIM/

.include <bsd.port.mk>
