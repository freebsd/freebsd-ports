# Created by: ijliao
# $FreeBSD$

PORTNAME=	gerbv
PORTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Free Gerber Viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=        pathfix pkgconfig
USE_GNOME=	desktopfileutils gtk20
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="${PORTVERSION}"

MAN1=		gerbv.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|desktop||g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/desktop/gerbv.desktop \
		${PREFIX}/share/applications
	@${MKDIR} ${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/desktop/gerbv.svg \
		${PREFIX}/share/icons/hicolor/scalable/apps
.for i in 16 22 24 32 48
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	${INSTALL_DATA} ${WRKSRC}/desktop/gerbv-${i}.png \
		${PREFIX}/share/icons/hicolor/${i}x${i}/apps/gerbv.png
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.fig ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/PNG-print
	${INSTALL_DATA} ${WRKSRC}/doc/PNG-print/*.jpg ${DOCSDIR}/PNG-print
	${INSTALL_DATA} ${WRKSRC}/doc/PNG-print/*.txt ${DOCSDIR}/PNG-print
	@${MKDIR} ${DOCSDIR}/eagle
	${INSTALL_DATA} ${WRKSRC}/doc/eagle/*.pl ${DOCSDIR}/eagle
	${INSTALL_DATA} ${WRKSRC}/doc/eagle/*.txt ${DOCSDIR}/eagle
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${FIND} . ! -name "*Makefile*" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif
	-@update-desktop-database

.include <bsd.port.mk>
