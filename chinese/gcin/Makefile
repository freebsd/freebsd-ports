PORTNAME=	gcin
PORTVERSION=	2.9.0
PORTREVISION=	4
CATEGORIES=	chinese textproc gnome
MASTER_SITES=	http://hyperrate.com/gcin-source/
EXTRACT_ONLY=	gcin-${PORTVERSION}.tar.xz

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Traditional Chinese input utility in X
WWW=		https://hyperrate.com/dir.php?eid=67

LICENSE=	LGPL21

BROKEN_powerpc64=	fails to build: gmake[3]: *** [Makefile:30: en-american] Error 255

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gmake gnome pkgconfig tar:xz xorg
HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--use_gtk3=N --use_qt5=N
USE_GNOME=	gtk30
USE_XORG=	x11 xtst xext
USE_LDCONFIG=	${PREFIX}/lib/gcin

OPTIONS_DEFINE=	ANTHY
OPTIONS_SUB=	yes
ANTHY_DESC=	Japanese anthy IM module

ANTHY_BUILD_DEPENDS=	${LOCALBASE}/include/anthy-unicode-1.0/anthy/anthy.h:japanese/anthy-unicode
ANTHY_LIB_DEPENDS=	libanthy-unicode.so:japanese/anthy-unicode
ANTHY_CONFIGURE_OFF=	--use_anthy=N
ANTHY_MAKE_ENV=		ANTHY_CFLAGS=-I${LOCALBASE}/include/anthy-unicode-1.0

post-patch:
	@${REINPLACE_CMD} -e 's,&,,; 1 s,##!/bin/bash,#!/bin/sh,; \
		s,-ldl,,; \
		s,/usr/share,$$prefix/share,; \
		1, 300 s,gcc,$$CC,; s,gcin-$$GCIN_VERSION,gcin,; \
		/GCIN_DEBUG/ d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,\/usr\/share,$$(prefix)\/share,; \
		s,%%PREFIX%%,${PREFIX},;' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/usr/local,/usr,g' \
		${WRKSRC}/menu/Makefile
	@${REINPLACE_CMD} -e 's,modify-XIM ,,; 8,10 d' \
		${WRKSRC}/scripts/Makefile
	@${REINPLACE_CMD} -e 's,bash,sh,; s/&//; s,/opt/gnome,${LOCALBASE},;' \
		${WRKSRC}/scripts/utf8-edit ${WRKSRC}/scripts/gcin-user-setup \
		${WRKSRC}/scripts/gtab.append_prepare \
		${WRKSRC}/scripts/tsin-gtab-import \
		${WRKSRC}/scripts/tsin-gtab-edit
	@${REINPLACE_CMD} -e 's,bash,sh,; s/&//; 12,13 s/=/ /; \
		s/export/setenv/; s/$$UTF8ED/xdg-open/' \
		${WRKSRC}/scripts/html-browser
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},' \
		${WRKSRC}/IMdkit/lib/Makefile ${WRKSRC}/Makefile \
		${WRKSRC}/qt-im/Makefile ${WRKSRC}/scripts/modify-XIM \
		${WRKSRC}/scripts/utf8-edit
	@${REINPLACE_CMD} -e '/make/ d' ${WRKSRC}/IMdkit/lib/Makefile
	@${REINPLACE_CMD} -e 's,/usr/X11R6/lib,${LOCALBASE}/lib,' ${WRKSRC}/im-client/Makefile

post-build:
.if !defined(DEBUG_FLAGS)
	@${FIND} ${WRKSRC} -name "*.so*" | ${XARGS} ${STRIP_CMD}
.endif

post-install:
.if !defined(DEBUG_FLAGS)
.for f in gcin* gtab-merge juyin-learn phoa2* sim2trad trad2sim ts-edit tsa2d32 tsd2a32 tsin2gtab-phrase tslearn
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
.endif

.include <bsd.port.mk>
