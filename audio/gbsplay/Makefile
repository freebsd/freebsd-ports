# New ports collection makefile for:	gbsplay
# Date created:				25 Jun 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	gbsplay
PORTVERSION=	0.0.7
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/gbsplay/
PKGNAMEPREFIX?=

MAINTAINER=	ehaupt@critical.ch
COMMENT?=	Emulates the sound hardware of the Nintendo Game Boy(TM)

USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}

.if ${PKGNAMEPREFIX} == ""

CONFIGURE_ARGS+=	--without-xmmsplugin

MAN1=		gbsplay.1 gbsinfo.1
MAN5=		gbsplayrc.5
PORTDOCS=	COPYRIGHT HISTORY README

OPTIONS=	NAS "NAS sound output" on

.endif

.include <bsd.port.pre.mk>

.if ${PKGNAMEPREFIX} == ""

.if defined(WITH_NAS)
LIB_DEPENDS+=	audio.2:${PORTSDIR}/audio/nas
.else
CONFIGURE_ARGS+=	--disable-nas
.endif

.endif

post-patch: gbsplay-post-patch
	@${REINPLACE_CMD} -e \
		's|/usr/local/include|${LOCALBASE}/include|; \
		 s|/usr/local/lib|${LOCALBASE}/lib|; \
		 s|/usr/X11R6/include|${X11BASE}/include|; \
		 s|/usr/X11R6/lib|${X11BASE}/lib|; \
		 s|-Os||; s|-pipe||; s|-fomit-frame-pointer||; \
		 s|-march=$$ARCH||' ${WRKSRC}/configure

.if ${PKGNAMEPREFIX} == ""

gbsplay-post-patch:
	@${REINPLACE_CMD} -e 's|/\(etc/gbsplayrc\)|${PREFIX}/\1|' \
		${WRKSRC}/gbsplay.c \
		${WRKSRC}/gbsplay.in.1 \
		${WRKSRC}/gbsplayrc.in.5

do-install:
.for f in ${PORTNAME} gbsinfo
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.for f in ${MAN1} ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/${f} ${MAN${f:E}PREFIX}/man/man${f:E}
.endfor
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/nightmode.gbs ${EXAMPLESDIR}

	${INSTALL_DATA} ${WRKSRC}/examples/gbsplayrc_sample ${PREFIX}/etc/gbsplayrc.default
.if !exists(${PREFIX}/etc/gbsplayrc)
	${INSTALL_DATA} ${WRKSRC}/examples/gbsplayrc_sample ${PREFIX}/etc/gbsplayrc
.endif

.for l in de en
	${INSTALL_DATA} ${WRKSRC}/po/${l}.mo ${PREFIX}/share/locale/${l}/LC_MESSAGES/gbsplay.mo
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.endif

.include <bsd.port.post.mk>
