# New ports collection makefile for: 	cvschk
# Date created:				2005-04-23
# Whom:					Matthias Andree <matthias.andree@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	cvschk
PORTVERSION=	1.12
CATEGORIES=	devel
MASTER_SITES=	http://cvs.sslug.dk/cvs2html/utils/
DISTNAME=	cvschk
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Quick offline checker for CVS modifications

USE_PERL5_RUN=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
MAN1=		cvschk.1

do-configure:
	${SED} -e "s,^#!/usr/bin/perl -w,#! ${PERL} -w," \
	<${DISTDIR}/${DISTNAME} >${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin
	${INSTALL_MAN}	  ${FILESDIR}/cvschk.1  ${PREFIX}/man/man1

.include <bsd.port.mk>
