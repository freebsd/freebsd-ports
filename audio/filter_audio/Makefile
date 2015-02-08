# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	filter_audio
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	audio
DIST_SUBDIR=	${PORTNAME}-${GH_COMMIT}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Lightweight audio filtering library made from webrtc code

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	irungentoo
GH_PROJECT=	filter_audio
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	9feb646

USES=		gmake
USE_LDCONFIG=	yes

PLIST_FILES=	include/filter_audio.h lib/libfilteraudio.so lib/libfilteraudio.so.0

post-install:
	${MV} ${STAGEDIR}${PREFIX}/lib/libfilteraudio.so ${STAGEDIR}${PREFIX}/lib/libfilteraudio.so.0 && \
	${LN} -sf libfilteraudio.so.0 ${STAGEDIR}${PREFIX}/lib/libfilteraudio.so

.include <bsd.port.mk>
