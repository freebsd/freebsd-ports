# Created by: Donald Burr <dburr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sourcenav
PORTVERSION=	4.5
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	sourcenavigator-NG${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Source code analysis tool

LICENSE=	GPLv2

USES=		shebangfix
SHEBANG_FILES=	${WRKSRC}/snavigator/demo/c++/contrib/perl/sample_client
USE_GCC=	yes
USE_BZIP2=	yes
USE_XORG=	x11

HAS_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--prefix=${PREFIX}/sourcenav

post-patch:
	${REINPLACE_CMD} -e 's|@XINCLUDES@|-I${LOCALBASE}/include|; \
	    s|@XLIBSW@|-L${LOCALBASE}/lib -lX11|' ${WRKSRC}/tk/unix/Makefile.in

post-install:
	${LN} -s ${PREFIX}/sourcenav/bin/snavigator ${STAGEDIR}${PREFIX}/bin/snavigator

.include <bsd.port.mk>
