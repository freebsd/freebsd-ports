# New ports collection makefile for:	cvs2html
# Date created:				Sun 02 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	cvs2html
PORTVERSION=	1.96
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sada
EXTRACT_SUFX=	.gz

MAINTAINER=	sada@FreeBSD.org
COMMENT=	Perl script to turn ``cvs log'' output into HTML

PLIST_FILES=	bin/cvs2html
USE_PERL5=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
EXTRACT_AFTER_ARGS=	> ${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
