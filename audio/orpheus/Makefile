# New ports collection Makefile for:	orpheus
# Date created:					9 December 2004
# Whom:						Andrej Zverev
#
# $FreeBSD$
#

PORTNAME=	orpheus
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://thekonst.net/download/

MAINTAINER=	az@inec.ru
COMMENT=	Light-weight console UI audio player application

RUN_DEPENDS=	mpg321:${PORTSDIR}/audio/mpg321

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_AUTOCONF_VER=	253

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	NLS	"Native language support"	on \
		CDDB	"CDDB audio CD' auto fetch track info support"	on \
		VORBIS	"Vorbis playing and tags edit support"	off

MAN1=	orpheus.1

.include <bsd.port.pre.mk>

.if defined(WITH_CDDB)
LIB_DEPENDS+=	ghttp:${PORTSDIR}/www/libghttp
CONFIGURE_ARGS+=	--enable-ghttp
.endif

.if defined(WITH_VORBIS)
RUN_DEPENDS+=	ogg123:${PORTSDIR}/audio/vorbis-tools
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
LIB_DEPENDS+=	vorbisfile:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--enable-vorbis
CONFIGURE_ARGS+=	--enable-vorbisfile
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	FAQ README ChangeLog
.endif

pre-configure:
	@cd ${WRKSRC}; ${AUTOCONF}
	@cd ${WRKSRC}/kkconsui-0.1; ${AUTOCONF}
	@cd ${WRKSRC}/kkstrtext-0.1; ${AUTOCONF}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/orpheus ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/orpheus.1 ${MAN1PREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
.if !defined(WITHOUT_NLS)
	${MKDIR} ${PREFIX}/share/locale/ru/LC_MESSAGES
	@${INSTALL_DATA} ${WRKSRC}/po/ru.gmo ${PREFIX}/share/locale/ru/LC_MESSAGES/orpheus.mo
.endif

.include <bsd.port.post.mk>
