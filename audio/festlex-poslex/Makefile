PORTNAME=	festlex-poslex
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	audio accessibility
MASTER_SITES=	FESTIVAL
DISTNAME=	festlex_POSLEX
DIST_SUBDIR=	festival
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	English lexicon for Festival

NO_BUILD=	yes
FHOME=		${PREFIX}/share/festival

do-install:
	${TAR} -C ${STAGEDIR}${FHOME:H} -xzvpf ${_DISTDIR}/${_DISTFILES}

.include <bsd.port.mk>
