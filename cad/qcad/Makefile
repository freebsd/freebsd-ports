# New ports collection makefile for:	qcad
# Date created:		10 Dec 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qcad
PORTVERSION=	2.0.3.3.1
PORTREVISION=	1

CATEGORIES=	cad
MASTER_SITES=	http://www.ribbonsoft.com/archives/qcad/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.1$/-1/}.src

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Professional CAD system

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2 \
		qmake:${PORTSDIR}/devel/qmake

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.1$/-1/}.src

QTDIR?=		${X11BASE}

USE_QT_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
PLIST=		${WRKDIR}/pkg-plist
MAKE_ENV=	QTDIR="${QTDIR}" MAKE="${GMAKE}" \
		QMAKESPEC="${LOCALBASE}/share/qt/mkspecs/freebsd-g++"

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
CFLAGS+=	-O0
.endif

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|streambuf<|streambuf\.h<|g' \
		${WRKSRC}/qcadguiqt/src/ui/qg_commandwidget.ui
.endif

do-build:
	cd ${WRKSRC}/scripts && ${SETENV} ${MAKE_ENV} bash ./build_qcad.sh

pre-install:
	@${ECHO_CMD} bin/qcad > ${PLIST}
	@${FIND} ${WRKSRC}/qcad/doc/ -type f | \
		${SED} -e "s:^${WRKSRC}/:%%PORTDOCS%%share/:g" >> ${PLIST}
	@${FIND} ${WRKSRC}/qcad/examples/ -type f | \
		${SED} -e "s:^${WRKSRC}/:%%PORTDOCS%%share/:g" >> ${PLIST}
	@${FIND} ${WRKSRC}/qcad/fonts/ -type f | \
		${SED} -e "s:^${WRKSRC}/:share/:g" >> ${PLIST}
	@${FIND} ${WRKSRC}/qcad/patterns/ -type f | \
		${SED} -e "s:^${WRKSRC}/:share/:g" >> ${PLIST}
	@${FIND} ${WRKSRC}/qcad/qm/ -type f | \
		${SED} -e "s:^${WRKSRC}/:share/:g" >> ${PLIST}
	@${FIND} ${WRKSRC}/qcad/scripts/ -type f | \
		${SED} -e "s:^${WRKSRC}/:share/:g" >> ${PLIST}
	@${FIND} -d ${WRKSRC}/qcad/doc -type d | \
		${SED} -e "s:^${WRKSRC}/:%%PORTDOCS%%@dirrm share/:g" >> ${PLIST}
	@${ECHO_CMD} '%%PORTDOCS%%@dirrm share/qcad/examples' >> ${PLIST}
	@${ECHO_CMD} '@dirrm share/qcad/fonts' >> ${PLIST}
	@${ECHO_CMD} '@dirrm share/qcad/patterns' >> ${PLIST}
	@${ECHO_CMD} '@dirrm share/qcad/qm' >> ${PLIST}
	@${ECHO_CMD} '@dirrm share/qcad/scripts/python' >> ${PLIST}
	@${ECHO_CMD} '@dirrm share/qcad/scripts' >> ${PLIST}
	@${ECHO_CMD} '@dirrm share/qcad' >> ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcad/qcad ${PREFIX}/bin/qcad
	@${MKDIR} ${DATADIR}
.for dir in fonts patterns qm scripts
	${TAR} -C ${WRKSRC}/qcad --exclude CVS -cf - ${dir} | \
		${TAR} -C ${DATADIR} --unlink -xf -
.endfor
.if !defined(NOPORTDOCS)
.for dir in doc examples
	${TAR} -C ${WRKSRC}/qcad --exclude CVS -cf - ${dir} | \
		${TAR} -C ${DATADIR} --unlink -xf -
.endfor
.endif

.include <bsd.port.post.mk>
