# New ports collection makefile for:	blokish
# Date created:				18 Jan 2006
# Whom:					Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	blokish
PORTVERSION=	0.9.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_src_v${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Clone of the strategy board game 'Blokus'

LIB_DEPENDS=	wx_base-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GL=		yes

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"

MAKEFILE=	makefile

WRKSRC=		${WRKDIR}/blokish

PLIST_FILES=	bin/blokish

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src-ai.h
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|wxgtk2-2.6-config|' ${WRKSRC}/makefile.in ${WRKSRC}/configure

.include <bsd.port.post.mk>
