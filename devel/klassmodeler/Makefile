# ex:ts=8
# Ports collection makefile for:	klassmodeler
# Date created:			Jun 29, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	klassmodeler
PORTVERSION=	0.8.2
CATEGORIES=	devel
MASTER_SITES=	http://www.jameswells.net/KlassModeler/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for visually creating and documenting classes

BROKEN=		Unfetchable

LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/Release
WX_CONFIG=	${X11BASE}/bin/wxgtk2-2.4-config
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ENV=	WXWINDOWS="yes"

PLIST_FILES=	bin/klassmodeler

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000                
BROKEN=		"Does not compile on 4.x"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,\`wx-config,\`${WX_CONFIG}," ${WRKSRC}/../configure

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/klassmodeler/klassmodeler ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/../klassmodeler/docs/en/*.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
