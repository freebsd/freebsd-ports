# New ports collection makefile for: 	cvslines
# Date created:				24 Aug 1998
# Whom:					jkoshy
#
# $FreeBSD$
#

PORTNAME=		cvslines
PORTVERSION=		1.6.7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_LOCAL} \
	http://www.netsw.org/softeng/versioncontrol/repository/cvs/cvslines/
MASTER_SITE_SUBDIR=	jkoshy

MAINTAINER=		trevor@FreeBSD.org

PLIST=			${WRKDIR}/pkg-plist
USE_PERL5=		yes
NO_BUILD=		yes

MAN1=	cvslines.1

pre-patch:
	${PERL} -pi -e "s:usr/local/bin/perl5:${PERL5}:g" ${WRKSRC}/cvslines
	${PERL} -pi -e "s:the the:the:g" ${WRKSRC}/cvslines.1

pre-install:
.for i in s s_check s-status s-check s-commit s-config
	${ECHO_CMD} bin/cvsline$i >> ${PLIST}
.endfor

do-install:
	PREFIX=${PREFIX} ${PERL5} ${WRKSRC}/INSTALL ${WRKSRC}/CONFIG

.include <bsd.port.mk>
