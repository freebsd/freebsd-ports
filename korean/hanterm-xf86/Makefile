# New ports collection makefile for:	hanterm-xf86
# Date created:		22 Mar 1997
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	hanterm
PORTVERSION=	18
CATEGORIES=	korean x11
MASTER_SITES=	http://www.kr.FreeBSD.org/~hwang/hanterm/
PKGNAMESUFFIX=	-xf
DISTNAME=	hanterm-xf-p18

MAINTAINER=	cjh@FreeBSD.org

RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/local/johabm16.pcf.gz:${PORTSDIR}/korean/johabfonts

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-x --enable-16-color
CONFIGURE_ENV+=		LIBS="-lxpg4"
NO_INSTALL_MANPAGES=	yes

post-install:
	@${INSTALL_DATA} ${WRKSRC}/Hanterm.ad ${PREFIX}/lib/X11/app-defaults/Hanterm

.include <bsd.port.mk>
