# New ports collection makefile for:	qcad
# Date created:		10 Dec 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qcad
PORTVERSION=	1.5.4
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

QTDIR?=		${X11BASE}

USE_QT_VER=	3
USE_REINPLACE=	yes
MAKE_ENV=	QTDIR="${QTDIR}"

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|warn_on|warn_on thread|g' ${WRKSRC}/qcad.pro
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/rprgdef.h

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${X11BASE}/mkspecs/freebsd-g++ qcad.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcad ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
.for dir in cur doc fonts hatches libraries messages xpm
	${TAR} -C ${WRKSRC} --exclude CVS --exclude hydraulics -cf - ${dir} | \
		${TAR} -C ${DATADIR} --unlink -xf -
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.dxf ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
