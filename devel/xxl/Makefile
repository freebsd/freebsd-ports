# Created by: Robert Schlotterbeck <robert@rs.tarrant.tx.us>
# $FreeBSD$

PORTNAME=	xxl
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/39195019/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C/C++ library for exception handling and asset management

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.if defined(WITHOUT_THREADS)
CONFIGURE_ARGS=	--without-threads
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	xxl.pdf xxl.html
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
