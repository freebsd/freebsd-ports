# New ports collection makefile for:	p5-jcode.pl
# Version required:			2.10
# Date created:				26 Jun 1998
# Whom:					SADA Kenji <sada@e-mail.ne.jp>
#
# $Id: Makefile,v 1.3 1998/09/15 05:40:30 kuriyama Exp $
#

DISTNAME=	ja-p5-jcode.pl-2.10
CATEGORIES=	japanese perl5
DISTFILES=

MAINTAINER=	sada@e-mail.ne.jp

RUN_DEPENDS=	${PREFIX}/lib/perl/jcode.pl:${PORTSDIR}/japanese/jcode.pl

NO_BUILD=	YES
USE_PERL5=	YES

INSTALL_DIR=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}

.SILENT:

do-install:
	${MKDIR} ${INSTALL_DIR}
	${LN} -sf ../../../perl/jcode.pl ${INSTALL_DIR}

.include <bsd.port.mk>
