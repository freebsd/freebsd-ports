# ex:ts=8
# Ports collection makefile for:	klassmodeler
# Date created:			Jun 29, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	klassmodeler
PORTVERSION=	0.8.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.jameswells.net/KlassModeler/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}.bsd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for visually creating and documenting classes

LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24

USE_ZIP=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
WX_CONFIG=	${X11BASE}/bin/wxgtk2-2.4-config
USE_GNOME=	gnometarget
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	WXWINDOWS="yes"

PLIST_FILES=	bin/klassmodeler

DOS2FIX=	configure Makefile.in klassmodeler/docs/en/Makefile.in \
		klassmodeler/docs/Makefile.in klassmodeler/Makefile.in \
		admin/depcomp klassmodeler/MainFrame.cpp

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

post-patch:
.for df in ${DOS2FIX}
	${MV} ${WRKSRC}/${df} ${WRKSRC}/${df}.dos
	${TR} -d '\r' < ${WRKSRC}/${df}.dos > ${WRKSRC}/${df}
.endfor
	@${REINPLACE_CMD} -e "s,\`wx-config,\`${WX_CONFIG}," ${WRKSRC}/${CONFIGURE_SCRIPT}
	${CHMOD} a+x ${WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/klassmodeler/klassmodeler ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/klassmodeler/docs/en/*.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
