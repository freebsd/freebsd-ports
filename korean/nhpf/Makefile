# New ports collection makefile for:    nhpf-1.42
# Version required:     1.42
# Date created:         25 May 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id$
#

DISTNAME=	nhpf-1.42
PKGNAME=	kr-nhpf-1.42
CATEGORIES=	korean www
MASTER_SITES=	ftp://cglab.snu.ac.kr/pub/hangul/n3f/applications/

MAINTAINER=	junker@jazz.snu.ac.kr

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nhpf ${PREFIX}/bin
	@strip ${PREFIX}/bin/nhpf

.include <bsd.port.mk>
