# New ports collection makefile for:	automake
# Date created:		15 March 1997
# Whom:			FUJIMOTO Kensaku <fujimoto@oscar.elec.waseda.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	automake
PORTVERSION=	1.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	automake

MAINTAINER=	fujimoto@oscar.elec.waseda.ac.jp

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL=${PERL5}
USE_PERL5=	yes

STRIP=		 # none

pre-configure:
	${PERL} -pi -e "s^%%X11BASE%%^${X11BASE}^" ${WRKSRC}/aclocal.in

post-install:
	@install-info ${PREFIX}/info/automake.info ${PREFIX}/info/dir

.include <bsd.port.mk>
