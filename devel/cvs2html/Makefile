# New ports collection makefile for:	cvs2html
# Date created:				Sun 02 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	cvs2html
PORTVERSION=	1.98
CATEGORIES=	devel perl5
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/${PORTVERSION}/ \
		http://cvs.sslug.dk/cvs2html/utils/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	utisoft@gmail.com
COMMENT=	Perl script to turn ``cvs log'' output into HTML

LICENSE=	GPLv2

PLIST_FILES=	bin/cvs2html
USE_PERL5=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
		${INSTALL_SCRIPT} ${DISTDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
