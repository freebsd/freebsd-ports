PORTNAME=	sgb
PORTVERSION=	20090810
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.stanford.edu/pub/sgb/
DISTNAME=	sgb-2009-08-10

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	The Stanford GraphBase: A Platform for Combinatorial Computing
WWW=		https://www-cs-faculty.stanford.edu/~knuth/sgb.html

BUILD_DEPENDS=	ctangle:devel/cweb

MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	lib tests

NO_WRKSUBDIR=	yes

post-extract:
	${CP} ${WRKSRC}/PROTOTYPES/* ${WRKSRC}

.include <bsd.port.mk>
