# New ports collection makefile for:	automake
# Date created:		15 March 1997
# Whom:			FUJIMOTO Kensaku <fujimoto@oscar.elec.waseda.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	automake17
PORTVERSION=	1.7.1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	automake
DISTNAME=	automake-${PORTVERSION}

MAINTAINER=	alane@FreeBSD.org

.undef		NO_IGNORE
BORKED=		"THIS IS A WORK IN PROGRESS. DON'T EVEN THINK ABOUT IT."
BROKEN=		${BORKED}
FORBIDDEN=	${BORKED}

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL=${PERL5}

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

do-build:
	${ECHO_MSG} This port is not ready yet.

do-install:
	${ECHO_MSG} I told you this port is not ready yet. Now go away.

.include <bsd.port.mk>
