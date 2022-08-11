PORTNAME=	beanie
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source accounting system

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dbow:databases/dbow
LIB_DEPENDS=	libexpat.so:textproc/expat2

LATE_INSTALL_ARGS=	BEANIEROOT="${STAGEDIR}${PREFIX}/beanie"
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${CP} ${WRKSRC}/beanie.mk.sample ${WRKSRC}/beanie.mk
	@${CP} ${WRKSRC}/tmac/lhead.sample.r ${WRKSRC}/tmac/lhead.r
# Fix the build with -fno-common (for Clang 11 and GCC 10)
	@${REINPLACE_CMD} -e 's,int[[:blank:]]*itemno,extern &,' \
		${WRKSRC}/import/salesorder.c

.include <bsd.port.mk>
