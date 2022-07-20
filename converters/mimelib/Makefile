PORTNAME=	mimelib
PORTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	SF/icqmail/libs/${PORTVERSION}

MAINTAINER=	never@nevermind.kiev.ua
COMMENT=	C++ class library for manipulating messages in MIME format

CONFLICTS=	kdenetwork-3.1.*

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-patch:
	${FIND} ${WRKSRC}/mimelib/ -name "*.cpp" -or -name "*.h" \
		| ${XARGS} ${REINPLACE_CMD} -e "s,iostream.h,iostream,"
	${TOUCH} ${WRKSRC}/mimelib/mimelib/Makefile.in ${WRKSRC}/stamp-h.in ${WRKSRC}/Makefile.in ${WRKSRC}/mimelib/Makefile.in

.include <bsd.port.post.mk>
