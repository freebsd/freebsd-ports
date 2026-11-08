PORTNAME=	ezstream
DISTVERSION=	1.0.2
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/ezstream/ \
		https://ftp.osuosl.org/pub/xiph/releases/ezstream/

MAINTAINER=	ayu@commun.jp
COMMENT=	Command for icecast line servers streaming to utility
WWW=		http://www.icecast.org/ezstream.php

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	check>=0.9.4:devel/check
LIB_DEPENDS=	libshout.so:audio/libshout

USES=		cpe gmake gnome iconv localbase:ldflags pkgconfig
CPE_VENDOR=	xiph
CPE_PRODUCT=	icecast_ezstream
USE_GNOME=	libxml2
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes

LDFLAGS+=	-lpthread

PORTDOCS=	NEWS README.md
PORTEXAMPLES=	artist.txt ezstream-file_template.xml ezstream-full.xml \
		ezstream-metadata.xml ezstream-minimal.xml ezstream-stdin.xml \
		ezstream-video.xml meta.sh play.sh playlist-logger.sh title.txt

OPTIONS_DEFINE=		DOCS EXAMPLES TAGLIB
OPTIONS_DEFAULT=	TAGLIB

TAGLIB_DESC=	support TagLib

TAGLIB_LIB_DEPENDS=	libtag.so:audio/taglib
TAGLIB_CONFIGURE_ON=	--with-taglib=${LOCALBASE}
TAGLIB_CONFIGURE_OFF=	--without-taglib

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}/
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${STAGEDIR}${EXAMPLESDIR}/
.endfor
	@${MKDIR} ${STAGEDIR}${ETCDIR}/

.include <bsd.port.mk>
