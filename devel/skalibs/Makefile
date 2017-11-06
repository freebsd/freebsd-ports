# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	skalibs
PORTVERSION=	2.4.0.2
CATEGORIES=	devel
MASTER_SITES=	http://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	colin-ports@heliocat.net
COMMENT=	General purpose C libraries used by skarnet.org software

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-default-path=${PREFIX}/bin:/usr/bin:/bin

DOCS=		AUTHORS README doc/*.html
OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libskarnet.so.${PORTVERSION}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
.for d in libbiguint libdatastruct librandom libstdcrypto libstddjb libunixonacid
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${d}
	cd ${WRKSRC} && ${INSTALL_MAN} doc/${d}/*.html ${STAGEDIR}${DOCSDIR}/${d}
.endfor

.include <bsd.port.mk>
