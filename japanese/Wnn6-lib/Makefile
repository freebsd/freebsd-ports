# New ports collection makefile for:	head files and libraries of Wnn6
# Date created:		11 July 1997
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Wnn6-lib
PORTVERSION=	2000.9.1
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.omronsoft.co.jp/pub/Wnn6/sdk_source/
DISTNAME=	Wnn6-SDK

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Include files and a library of Wnn6

BUILD_DEPENDS=	imake:${X_IMAKE_PORT}

WRKSRC=		${WRKDIR}/src/contrib/im/Xsi
DOCDIR=		${PREFIX}/share/doc/ja-Wnn6-lib

USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${X11BASE},g' \
		${WRKSRC}/config/Project.tmpl \
		${WRKSRC}/config/X11.tmpl \
		${WRKSRC}/Makefile.ini

# Warning: we cannot use USE_IMAKE.
do-build:
	( cd ${WRKSRC} ; make World -f Makefile.ini )

post-install:
	${LN} -sf libwnn6_fromsrc.a ${PREFIX}/lib/libwnn6.a
	@${MKDIR} ${PREFIX}/include/wnn6/wnn
	@${INSTALL_DATA} ${WRKSRC}/Wnn/include/*.h ${PREFIX}/include/wnn6/wnn
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include <bsd.port.mk>
