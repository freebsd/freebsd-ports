# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	skalibs
PORTVERSION=	2.3.8.0
CATEGORIES=	devel
MASTER_SITES=	http://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	colin@heliocat.net
COMMENT=	General purpose C libraries used by skarnet.org software

LICENSE=	ISCL

USES=		gmake
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--with-default-path=${PREFIX}/bin:/usr/bin:/bin

DOCS=		AUTHORS COPYING INSTALL README doc/*.html
OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libskarnet.so.${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${DOCS} ${STAGEDIR}${DOCSDIR}
.for d in libbiguint libdatastruct librandom libstdcrypto libstddjb libunixonacid
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${d}
	cd ${WRKSRC} && ${INSTALL_MAN} doc/${d}/*.html ${STAGEDIR}${DOCSDIR}/${d}
.endfor

.include <bsd.port.mk>
