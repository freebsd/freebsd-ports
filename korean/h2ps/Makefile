# New ports collection makefile for:    h2ps-2.0
# Version required:     2.0
# Date created:         20 May 1997
# Whom:                 CHOI Junho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.3 1997/11/22 01:17:55 asami Exp $
#

DISTNAME=	h2ps-2.00
PKGNAME=	ko-h2ps-a4-2.0
CATEGORIES=	korean print
MASTER_SITES=	ftp://cglab.snu.ac.kr/pub/hangul/n3f/tar/

MAINTAINER=	junker@jazz.snu.ac.kr

pre-build:
	@(cd ${WRKSRC}; make clean)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/h2ps ${PREFIX}/bin

.include <bsd.port.mk>
