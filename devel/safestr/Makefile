# Ports collection makefile for:        safestr
# Date created:                         28 Aug 2003
# Whom:                                 Robert Schlotterbeck <robert@rs.tarrant.tx.us>
#
# $FreeBSD$
#

PORTNAME=	safestr
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.zork.org/software/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A string handling library for C

LIB_DEPENDS=	xxl.2:${PORTSDIR}/devel/xxl:install

CONFIGURE_ARGS=	--with-xxl=${LOCALBASE}
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}/
.endif

.include <bsd.port.mk>
