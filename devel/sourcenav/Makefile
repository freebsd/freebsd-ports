# Created by: Donald Burr <dburr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sourcenav
PORTVERSION=	4.5
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/NG${PORTVERSION}
DISTNAME=	sourcenavigator-NG${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Source code analysis tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		fails to build: undefined reference to fpsetround

USES=		shebangfix tar:bzip2
SHEBANG_FILES=	${WRKSRC}/snavigator/demo/c++/contrib/perl/sample_client
USE_GCC=	yes
USE_XORG=	x11

HAS_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--prefix=${PREFIX}/sourcenav

post-patch:
	${REINPLACE_CMD} -e 's|@XINCLUDES@|-I${LOCALBASE}/include|; \
	    s|@XLIBSW@|-L${LOCALBASE}/lib -lX11|' ${WRKSRC}/tk/unix/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sourcenav/bin/wish8.3
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sourcenav/bin/tclsh8.3
	${LN} -s ${PREFIX}/sourcenav/bin/snavigator ${STAGEDIR}${PREFIX}/bin/snavigator

.include <bsd.port.mk>
