PORTNAME=	calceph
DISTVERSION=	4.0.5
CATEGORIES=	astro devel
MASTER_SITES=	https://www.imcce.fr/content/medias/recherche/equipes/asd/calceph/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Access the binary planetary ephemeris files
WWW=		https://www.imcce.fr/inpop/calceph/

LICENSE=	CeCILL
LICENSE_NAME=	Ce[a] C[nrs] I[nria] L[ogiciel] L[ibre] C license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake

USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include <bsd.port.mk>
