# New ports collection makefile for:	speyes
# Version required:			1.2.0
# Date created:				03 November 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	speyes-1.2.0
CATEGORIES=	games
MASTER_SITES=	http://www.halcyon.com/amalmin/speyes/

MAINTAINER=	jedgar@fxp.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

NO_INSTALL_MANPAGES= yes
USE_IMAKE=	yes

pre-configure:
	@${PERL} -pi.orig -e 's:__CFLAGS__:${CFLAGS}:g' ${WRKSRC}/Imakefile

.include <bsd.port.mk>
