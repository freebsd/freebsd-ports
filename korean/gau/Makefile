# New ports collection makefile for:    gau
# Version required:     0.3.1
# Date created:         23 Jul 1998
# Whom:                 CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	gau-0.3.1
PKGNAME=	ko-gau-0.3.1
CATEGORIES=	korean comms x11
MASTER_SITES=	http://pseudo.snu.ac.kr/~hwang/ \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	cjh@kr.freebsd.org

LIB_DEPENDS=    gtk10.1:${PORTSDIR}/korean/gtk10
RUN_DEPENDS=	lrz:${PORTSDIR}/comms/lrzsz \
		${PREFIX}/lib/X11/fonts/local/johabm16.pcf.gz:${PORTSDIR}/korean/johabfonts

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=  GTK_CONFIG="${X11BASE}/bin/gtk10-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

post-install:
	${RMDIR} ${PREFIX}/doc/gau-0.3.1/doc

.include <bsd.port.mk>
