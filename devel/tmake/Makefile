# New ports collection makefile for:	tmake
# Date created:				8 March 2000
# Whom:					jesse@cs.uni-magdeburg.de
#
# $FreeBSD$
#

PORTNAME=	tmake
PORTVERSION=	1.7
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	ftp://ftp.trolltech.com/freebies/tmake/

MAINTAINER=	jesse@cs.uni-magdeburg.de
COMMENT=	Extremely portable perl-based make utility

USE_PERL5=	yes
USE_QT_VER=	3
NO_BUILD=	yes
TMAKE_BIN=	progen tmake

REINPLACE_ARGS=	-i "" # no backup (for install)

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g; \
		s,/usr/X11R6,${X11BASE},g' \
		${WRKSRC}/lib/freebsd-g++/tmake.conf

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
