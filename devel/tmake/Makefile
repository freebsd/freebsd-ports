# New ports collection makefile for:	tmake
# Version required:			1.3
# Date created:				8 March 2000
# Whom:					jesse@cs.uni-magdeburg.de
#
# $FreeBSD$
#

DISTNAME=	tmake-1.3
CATEGORIES=	devel perl5
MASTER_SITES=	ftp://ftp.troll.no/freebies/tmake/

MAINTAINER=	jesse@cs.uni-magdeburg.de

USE_PERL5=	yes
NO_BUILD=       yes
WRKSRC=		${WRKDIR}/tmake
TMAKE_BIN=	progen tmake

do-install:
	@${MKDIR} ${PREFIX}/share/tmake
	@cd ${WRKSRC}/lib; tar cf - * | (cd ${PREFIX}/share/tmake && tar xf -)
.for f in ${TMAKE_BIN}
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${PREFIX}/bin
.endfor

post-install:
	@${ECHO} "Make sure to set your TMAKEPATH environment variable"
	@${ECHO} "to ${PREFIX}/share/tmake/freebsd-g++."
	@${ECHO}

.include <bsd.port.mk>
