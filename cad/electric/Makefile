# New ports collection makefile for:	electric
# Date created:		4 May 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	electric
PORTVERSION=	6.0.4
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/\1/}

MAINTAINER=	lioux@FreeBSD.org

USE_XLIB=	yes
USE_MOTIF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	-with-x

INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755

post-patch:
	@${PERL} -pi -e 's|/usr/local/lib/electric/|${PREFIX}/share/electric/lib/|; \
		s|/usr/local/|${PREFIX}/|' ${WRKSRC}/src/include/config.h
	@${PERL} -pi -e 's|/lib/electric|/share/electric/lib|' ${WRKSRC}/Makefile.in
	@${PERL} -pi -e 's|/usr/X11R6/|${X11BASE}/|' ${WRKSRC}/configure

.include <bsd.port.mk>
