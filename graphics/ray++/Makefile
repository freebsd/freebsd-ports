# ex:ts=8
# New ports collection makefile for:	ray++
# Date created:			Dec 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ray++
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	raypp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of C++ classes needed for ray tracing

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-fast-handles
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

post-patch:
	${REINPLACE_CMD} -e "s,-pedantic,," ${WRKSRC}/configure

do-install:
	@(cd ${WRKSRC} ; \
	  ${INSTALL_DATA} ray++.so ${PREFIX}/lib ; \
	  ${FIND} * -name "*.h" | ${CPIO} -pdum ${PREFIX}/include/${PORTNAME}; \
	  ${CHMOD} -R 755 ${PREFIX}/include/${PORTNAME} )

.include <bsd.port.post.mk>
