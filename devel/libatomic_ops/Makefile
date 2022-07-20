PORTNAME=	libatomic_ops
DISTVERSION=	7.6.12
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ivmai/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Atomic operations access library

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

USES=		cpe libtool pathfix
GNU_CONFIGURE=	yes

CPE_VENDOR=	libatomic_ops_project

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
