# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	libfilteraudio
PORTVERSION=	0.150524
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight audio filtering library made from webrtc code

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	irungentoo
GH_PROJECT=	filter_audio
GH_TAGNAME=	612c5a1

USES=		gmake
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|LIBDIR)/pkgconfig|LIBDIR)data/pkgconfig|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
