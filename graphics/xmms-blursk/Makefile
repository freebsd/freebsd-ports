# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	blursk
PORTVERSION=	1.3
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://web.cecs.pdx.edu/~kirkenda/blursk/
PKGNAMEPREFIX=	xmms-
DISTNAME=	Blursk-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS plugin inspired by "Blur Scope"

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	xmms>0:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms>0:${PORTSDIR}/multimedia/xmms

USES=		compiler
USE_XORG=	x11 xv
USE_GNOME=	gtk12
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

PLIST_FILES=	lib/xmms/Visualization/libblursk.so

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && ${COMPILER_TYPE} == "clang"
USE_BINUTILS=	yes
CPPFLAGS+=	-no-integrated-as
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-O2|| ; \
		 s|@PTHREAD_LIBS@||' ${WRKSRC}/Makefile.in

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/Visualization
	(cd ${WRKSRC}/.libs && ${INSTALL_LIB} libblursk.so \
		${STAGEDIR}${PREFIX}/lib/xmms/Visualization)
		
.include <bsd.port.post.mk>
