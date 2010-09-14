# New ports collection makefile for:	tmake
# Date created:				8 March 2000
# Whom:					jesse@cs.uni-magdeburg.de
#
# $FreeBSD$
#

PORTNAME=	tmake
PORTVERSION=	1.7
PORTREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	ftp://ftp.trolltech.com/freebies/tmake/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extremely portable perl-based make utility

USE_PERL5=	yes
NO_BUILD=	yes
TMAKE_BIN=	progen tmake

REINPLACE_ARGS=	-i "" # no backup (for install)

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g; \
		s,/usr/X11R6,${LOCALBASE},g' \
		${WRKSRC}/lib/freebsd-g++/tmake.conf

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/lib; tar cf - * | (cd ${DATADIR} && tar xf -)
	@${INSTALL_SCRIPT} ${TMAKE_BIN:S,^,${WRKSRC}/bin/,} ${PREFIX}/bin

post-install:
	@${ECHO}
	@${ECHO} "Make sure to set your TMAKEPATH environment variable"
	@${ECHO} "to ${DATADIR}/freebsd-g++."
	@${ECHO}

.include <bsd.port.mk>
