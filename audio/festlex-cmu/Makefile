PORTNAME=	festlex-cmu
PORTVERSION=	1.95
CATEGORIES=	audio accessibility
MASTER_SITES=	FESTIVAL
DISTNAME=	festlex_CMU
DIST_SUBDIR=	festival
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CMU American English pronunciation dictionary for Festival

NO_BUILD=	yes
FHOME=		${PREFIX}/share/festival

do-install:
	${TAR} -C ${STAGEDIR}${FHOME:H} -xzvpf ${_DISTDIR}/${_DISTFILES}

.include <bsd.port.mk>
