# New ports collection makefile for:	qcad
# Date created:		10 Dec 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qcad
PORTVERSION=	2.0.1.3
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://www.ribbonsoft.com/archives/qcad/
DISTNAME=	${PORTNAME}-${PORTVERSION}-${PORTREVISION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Professional CAD system

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-${PORTREVISION}.src

QTDIR?=		${X11BASE}

USE_QT_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ENV=	QTDIR="${QTDIR}" MAKE="${GMAKE}" \
		QMAKESPEC="${LOCALBASE}/share/qt/mkspecs/freebsd-g++"

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

#post-patch:
#	@${REINPLACE_CMD} -e 's|warn_on|warn_on thread|g' ${WRKSRC}/qcad.pro
#	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/rprgdef.h

#do-configure:
#	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
#		-spec ${X11BASE}/share/qt/mkspecs/freebsd-g++ qcad.pro

do-build:
	cd ${WRKSRC}/scripts && ${SETENV} ${MAKE_ENV} ${SH} ./build_qcad.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcad/qcad ${PREFIX}/bin/qcad
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/libraries
.for dir in fonts patterns qm scripts
	${TAR} -C ${WRKSRC}/qcad --exclude CVS -cf - ${dir} | \
		${TAR} -C ${DATADIR} --unlink -xf -
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/qcad/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
