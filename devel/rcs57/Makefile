# $FreeBSD$

PORTNAME=	rcs
PORTVERSION=	5.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Version control system (as was in FreeBSD prior to removal)

CONFLICTS=	rcs-5.[89]*
LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=	ci.1 co.1 ident.1 merge.1 rcs.1 rcsclean.1 rcsdiff.1 rcsmerge.1 rlog.1
MAN5=	rcsfile.5

NO_STAGE=	yes
.include <bsd.port.mk>
