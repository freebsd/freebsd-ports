# New ports collection makefile for:	hanterm3.04
# Date created:		12 Mar 1997
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	hanterm
PORTVERSION=	3.1.3
CATEGORIES=	korean x11
MASTER_SITES=	ftp://elf.kaist.ac.kr/pub/hanterm/ \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	cjh@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/lib/X11/fonts/local/johabm16.pcf.gz:${PORTSDIR}/korean/johabfonts

USE_IMAKE=	yes
NO_INSTALL_MANPAGES= yes

.include <bsd.port.mk>
