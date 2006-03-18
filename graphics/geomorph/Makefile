# ports collection makefile for:	geomorph
# Date created:		24 Feb 2006
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	geomorph
PORTVERSION=	0.31
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Height field generator and editor

LIB_DEPENDS=	gtkglext-x11-1.0.2:${PORTSDIR}/x11-toolkits/gtkglext

USE_X_PREFIX=	yes
USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-*
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libpng|libpng12|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/local/share/geomorph|${DATADIR}|' ${WRKSRC}/install-step* ${WRKSRC}/install-user ${WRKSRC}/src/app/app.c
	@${REINPLACE_CMD} -e 's|\$$HOME/geomorph|\$$HOME/.geomorph|' ${WRKSRC}/install-step* ${WRKSRC}/install-user
	@${REINPLACE_CMD} -e 's|>&|>|' ${WRKSRC}/install-step2-rcfile
	@${REINPLACE_CMD} -e '/DEFAULT_DIR/ s|geomorph|.geomorph|' ${WRKSRC}/src/app/globals.h ${WRKSRC}/src/hf/globals.h
	@${RM} ${WRKSRC}/install-step*.bak ${WRKSRC}/install-user*.bak

.include <bsd.port.post.mk>
