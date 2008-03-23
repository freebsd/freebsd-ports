# New ports collection makefile for:	head files and libraries of Wnn7
# Date created:		01/07/16
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Wnn7-lib
PORTVERSION=	2001.10.17
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.omronsoft.co.jp/pub/Wnn7/sdk_source/
DISTNAME=	Wnn7SDK
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Include files and a library of Wnn7

BUILD_DEPENDS=	imake:${X_IMAKE_PORT}

WRKSRC=		${WRKDIR}/src
DOCDIR=		${PREFIX}/share/doc/ja-Wnn7-lib

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${X11BASE},g' \
		${WRKSRC}/config/Project.tmpl \
		${WRKSRC}/config/X11.tmpl \
		${WRKSRC}/Makefile.ini

# Warning: we cannot use USE_IMAKE.
do-build:
	( cd ${WRKSRC} ; make World -f Makefile.ini )

post-install:
	@${MKDIR} ${PREFIX}/include/wnn7/wnn
	@${INSTALL_DATA} ${WRKSRC}/Wnn/include/*.h ${PREFIX}/include/wnn7/wnn
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include <bsd.port.post.mk>
