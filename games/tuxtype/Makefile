PORTNAME=	tuxtype
PORTVERSION=	1.8.3
PORTREVISION=	4
CATEGORIES=	games education
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Educational typing tutor starring Tux the Linux Penguin
WWW=		http://tux4kids.alioth.debian.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsed:textproc/gsed

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		autoreconf gettext gmake gnome iconv localbase perl5 pkgconfig \
		sdl
USE_GNOME=	libxml2
USE_SDL=	image mixer net pango sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/games
CONFIGURE_ENV=	ac_cv_lib_m_csin=yes

CPPFLAGS+=	-I${ICONV_INCLUDE_PATH}
LDFLAGS+=	${ICONV_LIB_PATH}

DESKTOP_ENTRIES="TuxType" "" "${DATADIR}/images/icons/icon.png" \
		"tuxtype" "" ""

OPTIONS_DEFINE=		DOCS SVG
OPTIONS_DEFAULT=	SVG
OPTIONS_SUB=		yes

SVG_USE=		gnome=librsvg2
SVG_CONFIGURE_WITH=	rsvg

post-patch:
	@${FIND} ${WRKSRC}/data -name "sed-linux.sh" | ${XARGS} \
		${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|; s|^sed |gsed |'
	@${REINPLACE_CMD} -e 's|\.\.\/ABOUT-NLS ||; s|COPYING ||; s|INSTALL ||' \
		${WRKSRC}/doc/Makefile.am
	@${REINPLACE_CMD} -e 's|-Wall -g |-Wall |; s|-DDEBUG ||' \
		${WRKSRC}/src/Makefile.am

post-configure:
	@${REINPLACE_CMD} -e 's|-R${LOCALBASE}/lib||' ${WRKSRC}/src/Makefile

.include <bsd.port.mk>
