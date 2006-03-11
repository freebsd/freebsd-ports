# New ports collection makefile for:	cvs2cl
# Date created:		6 June 2000
# Whom:			knu@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cvs2cl
PORTVERSION=	2.59
CATEGORIES=	devel
MASTER_SITES=	http://www.red-bean.com/cvs2cl/
DISTFILES=	${PORTNAME}.pl
EXTRACT_ONLY=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CVS-log-message-to-ChangeLog conversion script

USE_PERL5=	yes

NO_WRKSUBDIR=	yes
MANCOMPRESSED=	no
MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

do-extract:
	@${MKDIR} ${WRKSRC}

do-build:
	@${SED} -e "s^exec perl -w -x^exec /usr/local/bin/perl -w -x^; s^#!perl -w^#!/usr/local/bin/perl -w^ " \
		${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} > ${WRKSRC}/${PORTNAME}
	@pod2man ${WRKSRC}/${PORTNAME} > ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
