# ex:ts=8
# Ports collection makefile for:  bitedit
# Date created:			Tue Jul 18, 2002
# Whom:				Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$

PORTNAME=	bitedit
PORTVERSION=	0.9.2
CATEGORIES=	editors
MASTER_SITES=	http://ledge.co.za/software/bitedit/

MAINTAINER=	mich@freebsdcluster.org

MAKE_ARGS=	CFLAGS="${CFLAGS} -DDISABLE_SETFONT"

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bitedit ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/bitedit.txt ${DOCSDIR}/bitedit.txt
.endif

.include <bsd.port.mk>
