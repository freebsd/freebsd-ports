# New ports collection makefile for:    nhpf-1.42
# Version required:     1.42
# Date created:         25 May 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.2 1997/04/28 08:46:19 max Exp $
#

DISTNAME=	nhpf-1.42
PKGNAME=	ko-nhpf-1.42
CATEGORIES=	korean www
MASTER_SITES=	ftp://cglab.snu.ac.kr/pub/hangul/n3f/applications/

MAINTAINER=	junker@jazz.snu.ac.kr

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nhpf ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/nhpf
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nhpf
.endif
	@strip ${PREFIX}/bin/nhpf

.include <bsd.port.mk>
