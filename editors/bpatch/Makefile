PORTNAME=	bpatch
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	LOCAL/joerg
DISTNAME=	${PORTNAME}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Hex editor that doesn't load the whole file at once

# 2016-11-14: Email from Prof. (em.) John Rupley
# As far as I am concerned, the code is public domain, with no
# restrictions.  Steven List, in his README for the original
# distribution, said that the original author, Garry Johnson, gave him
# permission to place the code in the public domain.  So, do whatever
# you will with bpatch.  Nice to know it may still have a life.
LICENSE=	CC0-1.0

CONFLICTS_INSTALL=	bdelta

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/bpatch \
		man/man1/bpatch.1.gz

.include <bsd.port.mk>
