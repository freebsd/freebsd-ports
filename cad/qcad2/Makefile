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
USE_REINPLACE=	yes
USE_QT_VER=	3

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

post-patch:
	${REINPLACE_CMD} -e 's,warn_on,warn_on thread,' ${WRKSRC}/qcad.pro
	${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,' \
		${WRKSRC}/rconfig.cpp ${WRKSRC}/rprgdef.h\
		${WRKSRC}/rfonts.cpp ${WRKSRC}/rlibrarybrowser.cpp

pre-build:
	cd ${BUILD_WRKSRC}; qmake -spec ${X11BASE}/mkspecs/freebsd-g++ qcad.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcad ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
.for dir in cur fonts hatches libraries messages xpm
	${TAR} -C ${WRKSRC} --exclude CVS --exclude hydraulics -cf - ${dir} | \
		${TAR} -C ${DATADIR} --unlink -xf -
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc --exclude CVS -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${LN} -sf ${DOCSDIR} ${DATADIR}/doc
	@${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/examples --exclude CVS -cf - . | \
		${TAR} -C ${EXAMPLESDIR} --unlink -xf -
.endif

.include <bsd.port.post.mk>
