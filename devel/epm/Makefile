# Created by: NAKATA Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	epm
PORTVERSION=	4.2
CATEGORIES=	devel
MASTER_SITES=	http://www.msweet.org/files/project2/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_SUFX=	-source.tar.bz2

MAINTAINER=	office@FreeBSD.org
COMMENT=	Free UNIX software/file packaging program

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

MAKE_JOBS_UNSAFE=	yes
USES=		tar:bzip2
GNU_CONFIGURE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mkepmlist

.include <bsd.port.mk>
