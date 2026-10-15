PORTNAME=	cooledit
DISTVERSION=	5.0.6
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
RUN_DEPENDS=	Lohit>0:x11-fonts/lohit \
		google-fonts>0:x11-fonts/google-fonts \
		ja-sourcehansans-otf>0:japanese/sourcehansans-otf \
		noto-emoji>0:x11-fonts/noto-emoji \
		noto-music>0:x11-fonts/noto-music \
		noto-sans>0:x11-fonts/noto-sans \
		noto-sans-arabic-ui>0:x11-fonts/noto-sans-arabic-ui \
		noto-sans-armenian>0:x11-fonts/noto-sans-armenian \
		noto-sans-cham>0:x11-fonts/noto-sans-cham \
		noto-sans-cherokee>0:x11-fonts/noto-sans-cherokee \
		noto-sans-devanagari>0:x11-fonts/noto-sans-devanagari \
		noto-sans-ethiopic>0:x11-fonts/noto-sans-ethiopic \
		noto-sans-hebrew>0:x11-fonts/noto-sans-hebrew \
		noto-sans-kannada>0:x11-fonts/noto-sans-kannada \
		noto-sans-khmer>0:x11-fonts/noto-sans-khmer \
		noto-sans-lao>0:x11-fonts/noto-sans-lao \
		noto-sans-math>0:x11-fonts/noto-sans-math \
		noto-sans-myanmar>0:x11-fonts/noto-sans-myanmar \
		noto-sans-runic>0:x11-fonts/noto-sans-runic \
		noto-sans-sign-writing>0:x11-fonts/noto-sans-sign-writing \
		noto-sans-sinhala>0:x11-fonts/noto-sans-sinhala \
		noto-sans-symbols>0:x11-fonts/noto-sans-symbols \
		noto-sans-symbols2>0:x11-fonts/noto-sans-symbols2 \
		noto-sans-tamil>0:x11-fonts/noto-sans-tamil \
		noto-sans-telugu>0:x11-fonts/noto-sans-telugu \
		noto-sans-thai>0:x11-fonts/noto-sans-thai \
		noto-serif-georgian>0:x11-fonts/noto-serif-georgian

USES=		gettext-runtime libtool:build pkgconfig python xorg
USE_XORG=	x11 xt

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/${PORTNAME}

# Don't install bundled fonts
post-patch:
	@${REINPLACE_CMD} -e 's|man notosans|man|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
