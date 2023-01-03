PORTNAME=	libatomic_ops
DISTVERSION=	7.6.14
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ivmai/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Atomic operations access library
WWW=		https://github.com/ivmai/libatomic_ops

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

USES=		cpe libtool pathfix
CPE_VENDOR=	libatomic_ops_project
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared=yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
