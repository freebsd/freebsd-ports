# Created by: Matthias Andree <matthias.andree@gmx.de>
# $FreeBSD$

PORTNAME=	cvschk
PORTVERSION=	1.12
CATEGORIES=	devel
MASTER_SITES=	http://cvs.sslug.dk/cvs2html/utils/
DISTNAME=	cvschk
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Quick offline checker for CVS modifications

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-configure:
	${SED} -e "s,^#!/usr/bin/perl -w,#! ${PERL} -w," \
	<${DISTDIR}/${DISTNAME} >${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}	  ${FILESDIR}/cvschk.1  ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
