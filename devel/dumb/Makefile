# New ports collection makefile for:   dumb
# Date created:        26 January 2005
# Whom:                Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	dumb
PORTVERSION=	0.9.2
CATEGORIES=	devel audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dumb
DISTNAME=	${PORTNAME}-${PORTVERSION}-fixed

MAINTAINER=	andreas@syndrom23.de
COMMENT=	IT, XM, S3M and MOD player library

WRKSRC=		${WRKDIR}/dumb
USE_REINPLACE=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_ALLEGRO)
LIB_DEPENDS+=	alleg.41:${PORTSDIR}/devel/allegro
PLIST_SUB+=	ALLEGRO=""
.else
PLIST_SUB+=	ALLEGRO="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,-O2,${CFLAGS}," ${WRKSRC}/Makefile

pre-configure:
	@${CP} ${FILESDIR}/config.txt ${WRKSRC}/make
	@${REINPLACE_CMD} -e "s,@LOCALBASE@,${LOCALBASE}," ${WRKSRC}/make/config.txt
.if defined(WITH_ALLEGRO)
	@${REINPLACE_CMD} -e "s,@ALLEGRO@,," ${WRKSRC}/make/config.txt
.else
	@${REINPLACE_CMD} -e "s,@ALLEGRO@,#," ${WRKSRC}/make/config.txt
.endif

.include <bsd.port.post.mk>
