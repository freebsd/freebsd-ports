PORTNAME=	skalibs
PORTVERSION=	2.12.0.1
CATEGORIES=	devel
MASTER_SITES=	https://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	crest@rlwinm.de
COMMENT=	General purpose C libraries used by skarnet.org software

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_mips64=		fails to build: Checking whether system has auto-close after fd-passing... test crashed, aborting

USES=		gmake
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-default-path=${PREFIX}/bin:/usr/bin:/bin

OPTIONS_DEFINE=	DOCS

DOCS=		AUTHORS README doc/*.html

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libskarnet.so.${PORTVERSION}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
.for d in libdatastruct libposixplz librandom libstdcrypto libstddjb libunixonacid
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${d}
	cd ${WRKSRC} && ${INSTALL_DATA} doc/${d}/*.html ${STAGEDIR}${DOCSDIR}/${d}
.endfor

.include <bsd.port.mk>
