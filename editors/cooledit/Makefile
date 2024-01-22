PORTNAME=	cooledit
DISTVERSION=	4.1.2
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SUNSITE/apps/editors/X/cooledit

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	CoolEdit Programmers Code Editor
WWW=		https://github.com/paulsheer/cooledit

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/COPYRIGHT.bsd
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYRIGHT.gpl

LIB_DEPENDS=	libfreetype.so:print/freetype2
RUN_DEPENDS=	font-misc-misc>0:x11-fonts/font-misc-misc \
		noto-basic>0:x11-fonts/noto-basic \
		noto-emoji>0:x11-fonts/noto-emoji \
		noto-extra>0:x11-fonts/noto-extra

USES=		gettext-runtime libtool:build pkgconfig python xorg
USE_XORG=	x11 xt

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		CJK
CJK_DESC=		Chinese, Japanese and Korean fonts
CJK_RUN_DEPENDS=	noto-hk>0:x11-fonts/noto-hk \
			noto-jp>0:x11-fonts/noto-jp \
			noto-kr>0:x11-fonts/noto-kr \
			noto-sc>0:x11-fonts/noto-sc \
			noto-tc>0:x11-fonts/noto-tc

# Don't install bundled fonts
post-patch:
	@${REINPLACE_CMD} -e 's|man notosans|man|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
