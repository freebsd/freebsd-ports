# New ports collection makefile for:  lclint
# Version required:	2.4b
# Date created: 	9 September 1996
# Whom:			moeding
#
# $FreeBSD$
#

DISTNAME=	lclint-2.4b
CATEGORIES=	devel
MASTER_SITES= 	http://www.sds.lcs.mit.edu/lclint/ftp/lclint/ \
		ftp://ftp.deva.net/pub/sources/programming/linting/ \
		ftp://ftp.netsw.org/netsw/SoftEng/Lang/C/Tools/lclint/ \
		ftp://ftp.uni-bielefeld.de/pub/programming/tools/lclint/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	s.moeding@ndh.net

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

do-build:
	@(cd ${WRKSRC}; ${GMAKE})

post-install:
	@strip ${PREFIX}/bin/lclint

.include <bsd.port.mk>
