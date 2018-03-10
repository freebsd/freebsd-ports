# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	gbsplay
PORTVERSION=	0.0.93.20161217
PORTREVISION=	3
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Emulates the sound hardware of the Nintendo Game Boy(TM)

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	mmitch
GH_TAGNAME=	2c4486e

HAS_CONFIGURE=	yes
USES=		gmake compiler:gcc-c++11-lib
USE_CSTD=	gnu89

CONFIGURE_ARGS+=	--prefix=${PREFIX}

CONFIGURE_ARGS+=	--without-xmmsplugin

MANPAGE1=	gbsplay.1 gbsinfo.1
MANPAGE5=	gbsplayrc.5
PORTDOCS=	COPYRIGHT HISTORY README

OPTIONS_DEFINE=	DOCS NAS NLS
OPTIONS_SUB=	yes

NAS_LIB_DEPENDS=	libaudio.so:audio/nas
NAS_CONFIGURE_ENABLE=	nas
NLS_CONFIGURE_OFF=	--disable-i18n
NLS_USES=		gettext
NLS_LDFLAGS=		-L${LOCALBASE}/lib -lintl

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
		-e 's|^\(default.*\)test|\1|' \
		-e 's#md5sum | cut -f1 -d..#md5 -q#' \
		${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e \
		'/^need_include\ /d; \
		 468s|char argc|int argc|; \
		 s|/usr/local/include|${LOCALBASE}/include|; \
		 s|/usr/local/lib|${LOCALBASE}/lib|; \
		 s|/usr/X11R6/include||; \
		 s|/usr/X11R6/lib||; \
		 s|/usr/X11/lib|${LOCALBASE}/lib|; \
		 s|/usr/lib/X11|${LOCALBASE}/lib/X11|; \
		 s|-Os||; s|-pipe||; s|-fomit-frame-pointer||; \
		 s|-march=$$ARCH||' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/\(etc/gbsplayrc\)|${PREFIX}/\1|' \
		${WRKSRC}/gbsplay.c \
		${WRKSRC}/gbsplay.in.1 \
		${WRKSRC}/gbsplayrc.in.5

do-install:
.for f in ${PORTNAME} gbsinfo
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

.for f in ${MANPAGE1} ${MANPAGE5}
	${INSTALL_MAN} ${WRKSRC}/${f} ${STAGEDIR}${MAN${f:E}PREFIX}/man/man${f:E}
.endfor

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/nightmode.gbs \
		${STAGEDIR}${EXAMPLESDIR}

	${INSTALL_DATA} ${WRKSRC}/examples/gbsplayrc_sample \
		${STAGEDIR}${PREFIX}/etc/gbsplayrc.sample
.if !exists(${STAGEDIR}${PREFIX}/etc/gbsplayrc)
	${INSTALL_DATA} ${WRKSRC}/examples/gbsplayrc_sample \
		${STAGEDIR}${PREFIX}/etc/gbsplayrc
.endif

.if ${PORT_OPTIONS:MNLS}
.for l in de en
	${INSTALL_DATA} ${WRKSRC}/po/${l}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${l}/LC_MESSAGES/gbsplay.mo
.endfor
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
