# New ports collection makefile for:	automake
# Date created:		15 March 1997
# Whom:			FUJIMOTO Kensaku <fujimoto@oscar.elec.waseda.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	automake
PORTVERSION=	1.5
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	automake

MAINTAINER=	alane@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL=${PERL5}
USE_PERL5=	yes

STRIP=		# none

.if defined(USE_AUTOMAKE) || defined(USE_AUTOMAKE_VER)
pre-everything:
	@${ECHO} ===========================================================
	@${ECHO} "You have 'USE_AUTOMAKE' or 'USE_AUTOMAKE_VER' variables"
	@${ECHO} "defined either in environment or in make(1) arguments."
	@${ECHO} "Please undefine them and try again."
	@${ECHO} ===========================================================
	@${FALSE}
.endif # defined(USE_AUTOMAKE) || defined(USE_AUTOMAKE_VER)

pre-configure:
	${PERL} -pi -e "s^%%X11BASE%%^${X11BASE}^" ${WRKSRC}/aclocal.in

post-install:
	@install-info ${PREFIX}/info/automake.info ${PREFIX}/info/dir

.include <bsd.port.mk>
