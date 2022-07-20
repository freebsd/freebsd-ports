PORTNAME=	data.table
DISTVERSION=	1.14.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Extension of Data.frame

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cran:auto-plist

OPTIONS_DEFINE=		OPENMP
OPTIONS_DEFAULT=	OPENMP

OPENMP_CONFIGURE_ENABLE=	openmp

NO_ARCH_IGNORE=		datatable.so

.include <bsd.port.options.mk>

.if defined(PPC_ABI) && ${PPC_ABI} == ELFv1
USE_GCC=	yes
.else
USES+=		cran:compiles
.endif

.include <bsd.port.mk>
