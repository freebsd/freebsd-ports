# New ports collection makefile for:	cvs2cl
# Date created:		6 June 2000
# Whom:			knu@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cvs2cl
PORTVERSION=	2.58
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
MANCOMPRESSED=	no
MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME} 

do-extract:
	${MKDIR} ${WRKSRC}
	${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} > ${WRKSRC}/${PORTNAME}

do-build:
	pod2man ${WRKSRC}/${PORTNAME} > ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
