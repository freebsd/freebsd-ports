# Created by: ijliao
# $FreeBSD$

PORTNAME=	clint
PORTVERSION=	0.1.2
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Static source code checker for C++

LICENSE=	GPLv2

USE_AUTOTOOLS=	libtool
USE_PYTHON=	2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--enable-python=${LOCALBASE}/bin/python2
USE_LDCONFIG=	yes
USE_GCC=	any
USE_CSTD=	gnu99
USE_CXXSTD=	gnu++98
USES=		gmake
INFO=		clint
MAKE_JOBS_UNSAFE=	yes
BROKEN=		fails to find python.h

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-ldl||g'
	${REINPLACE_CMD} -E 's,(DEFS = @DEFS@ -I. -I$$\(srcdir\)),\1 -I${LOCALBASE}/include -I${LOCALBASE}/include/${PYTHON_VERSION}/,g' ${WRKSRC}/lib/python/Makefile.in 
	${REINPLACE_CMD} -E '100s,$$, -I${LOCALBASE}/include -I${LOCALBASE}/include/${PYTHON_VERSION}/,g' ${WRKSRC}/plugins/python/Makefile.in

.include <bsd.port.mk>
