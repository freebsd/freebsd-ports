# New ports collection makefile for:	cons
# Date created:		11 December 1998
# Whom:			rv@gnu.org
#
# $FreeBSD$
#

PORTNAME=	cons
PORTVERSION=	2.2.0
CATEGORIES=	devel
MASTER_SITES=	http://www.dsmit.com/cons/stable/ \
		http://www.gnu.org/software/cons/stable/ \
		ftp://ftp.gnu.org/pub/gnu/cons/ \
		http://www.baldmt.com/cons/stable/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rv@gnu.org
COMMENT=	A Perl-based Make Replacement

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

USE_PERL5=	yes
NO_BUILD=	yes
PLIST_SUB=	CONS_VER=${PORTVERSION}

MANCOMPRESSED=	yes
MAN1=		cons.1
DOCS=		CHANGES COPYING COPYRIGHT INSTALL MANIFEST README RELEASE \
		cons.html TODO

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cons ${PREFIX}/bin/cons
	${INSTALL_MAN} ${WRKSRC}/cons.1.gz ${PREFIX}/man/man1/cons.1.gz
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PKGNAME}
.for f in ${DOCS}
	${INSTALL} -c ${WRKSRC}/$f ${PREFIX}/share/doc/${PKGNAME}
.endfor
.endif

.include <bsd.port.mk>
