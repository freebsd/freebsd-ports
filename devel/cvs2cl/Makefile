# New ports collection makefile for:	cvs2cl
# Date created:		6 June 2000
# Whom:			knu@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cvs2cl
PORTVERSION=	2.49
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.iDaemons.org/pub/distfiles/
MASTER_SITE_SUBDIR=	knu
DISTFILES=	${PORTNAME}.pl-${PORTVERSION}.gz
EXTRACT_ONLY=	# none

MAINTAINER=	knu@FreeBSD.org
COMMENT=	CVS-log-message-to-ChangeLog conversion script

USE_PERL5=	yes

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/cvs2cl

do-extract:
	${MKDIR} ${WRKDIR}
	${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} > ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
