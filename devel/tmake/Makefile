# New ports collection makefile for:	tmake
# Date created:				8 March 2000
# Whom:					jesse@cs.uni-magdeburg.de
#
# $FreeBSD$
#

PORTNAME=	tmake
PORTVERSION=	1.7
CATEGORIES=	devel perl5
MASTER_SITES=	ftp://ftp.trolltech.com/freebies/tmake/

MAINTAINER=	jesse@cs.uni-magdeburg.de

USE_PERL5=	yes
USE_QT_VER=	2
NO_BUILD=	yes
TMAKE_BIN=	progen tmake

do-install:
	@${MKDIR} ${PREFIX}/share/tmake
	@cd ${WRKSRC}/lib; tar cf - * | (cd ${PREFIX}/share/tmake && tar xf -)
.for f in ${TMAKE_BIN}
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${PREFIX}/bin
.endfor

post-install:
	@${ECHO}
	@${ECHO} "Make sure to set your TMAKEPATH environment variable"
	@${ECHO} "to ${PREFIX}/share/tmake/freebsd-g++."
	@${ECHO}

.include <bsd.port.mk>
