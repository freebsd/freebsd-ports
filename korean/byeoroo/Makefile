# New ports collection makefile for:	byeoroo
# Date created:		04 Jun 1999
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	byeoroo
PORTVERSION=	0.0.19990605.3
PORTREVISION=	1
CATEGORIES=	korean x11
MASTER_SITES=	http://master.debian.or.kr/~cwryu/archive/byeoroo/

MAINTAINER=	cjh@FreeBSD.org

BROKEN=		"Does not compile"

RUN_DEPENDS=	${PREFIX}/lib/X11/fonts/local/johabm16.pcf.gz:${PORTSDIR}/korean/johabfonts \
		${X11BASE}/lib/X11/fonts/local/gulim12.pcf.gz:${PORTSDIR}/korean/baekmukfonts-bdf

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
