# New ports collection makefile for:	hanterm3.04
# Version required:     3.04beta7
# Date created:		12 Mar 1997
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

DISTNAME=	hanterm-3.1.3
PKGNAME=	ko-hanterm-3.1.3
CATEGORIES=	korean x11
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/ \
		http://www.freebsd.org/~sada/distfiles/

MAINTAINER=	cjh@kr.freebsd.org

RUN_DEPENDS=	${PREFIX}/lib/X11/fonts/local/johabm16.pcf.gz:${PORTSDIR}/korean/johabfonts

USE_IMAKE=	yes
NO_INSTALL_MANPAGES= yes

.include <bsd.port.mk>
