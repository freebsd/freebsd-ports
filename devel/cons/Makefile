# New ports collection makefile for:	cons
# Version required:     1.6b1
# Date created:		11 December 1998
# Whom:			rv@fore.com
#
# $FreeBSD$
#

DISTNAME=	cons-${CONSVER}
CATEGORIES=	devel
MASTER_SITES=	http://www.dsmit.com/cons/ \
		http://www.telerama.com/~bgarcia/cons/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rv@fore.com

RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/MD5.pm:${PORTSDIR}/security/p5-MD5

CONSVER=	1.7

USE_PERL5=	yes
NO_BUILD=	yes
PLIST_SUB=	CONS_VER=${CONSVER}

MAN1=		cons.1
DOCS=		CHANGES COPYRIGHT INSTALL MANIFEST README RELEASE cons.html

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
