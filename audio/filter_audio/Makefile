# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	filter_audio
PORTVERSION=	0.150317
CATEGORIES=	audio
DIST_SUBDIR=	${PORTNAME}-${GH_COMMIT}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Lightweight audio filtering library made from webrtc code

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	irungentoo
GH_PROJECT=	filter_audio
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	2ebc753

USES=		gmake
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|LIBDIR)/pkgconfig|LIBDIR)data/pkgconfig|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
