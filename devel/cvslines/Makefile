# New ports collection makefile for: 	cvslines
# Date created:				24 Aug 1998
# Whom:					jkoshy
#
# $FreeBSD$
#

PORTNAME=		cvslines
PORTVERSION=		1.6.9
CATEGORIES=		devel
MASTER_SITES=		SF

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Wrapper to ease merging of changes between CVS branches

WRKSRC=			${WRKDIR}/${PORTNAME}
USE_PERL5=		yes
NO_BUILD=		yes
.for ii in s s_check s-check s-commit s-config s-status
PLIST_FILES+=	bin/cvsline${ii}
.endfor

MAN1=	cvslines.1

pre-patch:
	${PERL} -pi -e "s:usr/bin/perl5:${PERL5}:g" ${WRKSRC}/cvslines
	${PERL} -pi -e "s:the the:the:g" ${WRKSRC}/cvslines.1

do-install:
	PREFIX=${PREFIX} ${PERL5} ${WRKSRC}/INSTALL ${WRKSRC}/CONFIG

.include <bsd.port.mk>
