# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	longplayer
# Date created:		2002-12-16
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	lplayer
PORTVERSION=	0.98.1
PORTREVISION=	1
#PORTEPOCH=
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	alane@FreeBSD.org

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms

USE_QT_VER=	3
USE_GMAKE=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
MAKE_ENV+=	QTDIR=${QT_PREFIX}
CONFIGURE_ENV=	${MAKE_ENV}

do-configure:
	cd ${WRKSRC}; \
	XMMSLIBS=$$(xmms-config --libs); \
	XMMSINCS=$$(xmms-config --cflags | sed 's|-I||g'); \
	${REINPLACE_CMD} -e "s|@X11BASE@|${X11BASE}|g" \
		-e "s|@LOCALBASE@|${LOCALBASE}|g" \
		-e "s|@XMMSLIBS@|$$XMMSLIBS|" \
		-e "s|@XMMSINCS@|$$XMMSINCS|" lp.pro; \
	${SETENV} ${CONFIGURE_ENV} qmake -makefile -o Makefile -unix lp.pro

.include <bsd.port.pre.mk>

DOCS_SUBDIR=		${DOCSDIR:S|^${PREFIX}/||}
EXAMPLES_SUBDIR=	${EXAMPLESDIR:S|^${PREFIX}/||}

BINDIR=			${PREFIX}/bin
BIN_SUBDIR=		${BINDIR:S|^${PREFIX}/||}
LIBDIR=			${PREFIX}/lib
LIB_SUBDIR=		${LIBDIR:S|^${PREFIX}/||}
PKGLIBDIR=		${LIBDIR}/${PORTNAME}
PKGLIB_SUBDIR=		${PKGLIBDIR:S|^${PREFIX}/||}

do-install:
	${MKDIR} ${BINDIR} ${PKGLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-bin ${PKGLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/../gnu/lplayerdir/*.png ${PKGLIBDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/lplayer ${BINDIR}

.include <bsd.port.post.mk>

#EOF
