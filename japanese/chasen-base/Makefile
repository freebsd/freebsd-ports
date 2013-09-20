# Created by: kuriyama
# $FreeBSD$

PORTNAME=	chasen
PORTVERSION=	2.4.4
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=     chasen-legacy/32224
PKGNAMESUFFIX=	-base

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese Morphological Analysis System

BUILD_DEPENDS=	${LOCALBASE}/include/darts.h:${PORTSDIR}/devel/darts

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-darts=${LOCALBASE}/include ${ICONV_CONFIGURE_BASE}
USES=		iconv
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-install:
	${RM} -f ${PREFIX}/lib/libchasen.la
	${MKDIR} ${PREFIX}/share/chasen/dic
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/manual* ${DOCSDIR}
.endif

.include <bsd.port.mk>
