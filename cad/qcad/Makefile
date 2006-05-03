# New ports collection makefile for:	qcad
# Date created:		10 Dec 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qcad
PORTVERSION=	2.0.5.0.1
#PORTREVISION=	1

CATEGORIES=	cad
MASTER_SITES=	http://www.ribbonsoft.com/archives/qcad/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.1$/-1/}-community.src

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Professional CAD system

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2 \
		qmake:${PORTSDIR}/devel/qmake

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.1$/-1/}-community.src

QTDIR?=		${X11BASE}

USE_X_PREFIX=	yes
USE_QT_VER=	3
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
	cd ${WRKSRC}/scripts && ${SETENV} ${MAKE_ENV} bash ./build_qcad.sh notrans

pre-install:
	@${ECHO_CMD} bin/qcad > ${PLIST}
.for dir in data fonts patterns qm scripts
	@${FIND} ${WRKSRC}/qcad/${dir} -type f | \
		${SED} -e "s:^${WRKSRC}/:share/:g" >> ${PLIST}
.endfor
	@${FIND} ${WRKSRC}/qcad/doc -type f | \
	${SED} -e "s:^${WRKSRC}/qcad/doc/:%%PORTDOCS%%share/doc/qcad/:g" >> \
		${PLIST}
	@${FIND} -d ${WRKSRC}/qcad/doc -type d | \
	${SED} -e "s:^${WRKSRC}/qcad/doc:%%PORTDOCS%%@dirrm share/doc/qcad:g" \
		>> ${PLIST}
.for dir in scripts qm patterns fonts data
	@${FIND} -d ${WRKSRC}/qcad/${dir} -type d | \
	${SED} -e "s:^${WRKSRC}/qcad/${dir}:@dirrm share/qcad/${dir}:g" >> \
		${PLIST}
.endfor
	@${ECHO_CMD} '@dirrm share/qcad' >> ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcad/qcad ${PREFIX}/bin/qcad
	@${MKDIR} ${DATADIR}
.for dir in data fonts patterns qm scripts
	${TAR} -C ${WRKSRC}/qcad --exclude CVS -cf - ${dir} | \
		${TAR} -C ${DATADIR} --unlink -xf -
.endfor
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}
.for dir in doc
	${TAR} -C ${WRKSRC}/qcad/${dir} --exclude CVS -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
.endfor
.endif

.include <bsd.port.post.mk>
