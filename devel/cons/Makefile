# New ports collection makefile for:	cons
# Date created:		11 December 1998
# Whom:			rv@dsmit.com
#
# $FreeBSD$
#

PORTNAME=	cons
PORTVERSION=	1.8.d
CATEGORIES=	devel
MASTER_SITES=	http://www.dsmit.com/cons/
DISTNAME=	cons-1.8-dev
EXTRACT_SUFX=	.tgz

MAINTAINER=	rv@dsmit.com

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MD5.pm:${PORTSDIR}/security/p5-MD5

USE_PERL5=	yes
NO_BUILD=	yes
PLIST_SUB=	CONS_VER=${PORTVERSION}

MAN1=		cons.1
DOCS=		CHANGES COPYRIGHT INSTALL MANIFEST README RELEASE cons.html \
		TODO test.log

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cons ${PREFIX}/bin/cons
	${INSTALL_MAN} ${WRKSRC}/cons.1 ${PREFIX}/man/man1/cons.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PKGNAME}
.for f in ${DOCS}
	${INSTALL} -c ${WRKSRC}/$f ${PREFIX}/share/doc/${PKGNAME}
.endfor
.endif

.include <bsd.port.mk>
