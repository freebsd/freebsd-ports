# Created by: Gabor Kovesdan <gabor@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opencvs
PORTVERSION=	20130930
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	johans

MAINTAINER=	johans@FreeBSD.org
COMMENT=	BSD-licensed CVS implementation

LICENSE=	BSD2CLAUSE

WRKSRC=		${WRKDIR}/cvs

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		MANDIR="${MANPREFIX}/man/man" \
		CATDIR="${MANPREFIX}/man/man"

PLIST_FILES=	bin/opencvs \
		man/man1/opencvs.1.gz \
		man/man5/opencvs.5.gz \
		man/man7/cvsintro.7.gz

.include <bsd.port.mk>
