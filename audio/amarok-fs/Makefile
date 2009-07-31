# New ports collection makefile for:	amarok-fs
# Date created:				20 June 2007
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	amarok-fs
PORTVERSION=	0.5
PORTREVISION=	5
CATEGORIES=	audio kde
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	52641-amarokFS-${PORTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	A full screen application for Amarok

PATCH_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
BUILD_DEPENDS=	${PATCH_DEPENDS}
RUN_DEPENDS=	amarok:${PORTSDIR}/audio/amarok

USE_GMAKE=	yes
USE_KDELIBS_VER=3
INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/amarokFS-${PORTVERSION}

PORTDOCS=	README theme-howto.txt

MAKE_ENV+=	QTDIR="${QT_PREFIX}" QMAKESPEC="freebsd-g++"

DOCSDIR=	${PREFIX}/share/doc/amarokFS

QMAKE=		${LOCALBASE}/bin/qmake -unix -o

.include <bsd.port.pre.mk>

post-extract:
	${REINPLACE_CMD} -e 's|/usr/share/icons/amarokFS.png|amarokFS|' \
		${WRKSRC}/amarokFS.desktop
	${REINPLACE_CMD} -e 's|/usr/share/|${PREFIX}/share/|g' \
		${WRKSRC}/amfs-xml.cpp

post-patch:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${QMAKE} Makefile amarokFS-xml.pro

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
