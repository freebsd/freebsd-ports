# New ports collection makefile for:	qcad
# Date created:		10 Dec 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qcad
PORTVERSION=	2.0.5.0.1
PORTREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	ftp://www.ribbonsoft.com/archives/qcad/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.1$/-1/}-community.src

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Professional CAD system

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		qmake:${PORTSDIR}/devel/qmake

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.1$/-1/}-community.src

QTDIR?=		${QT_PREFIX}

USE_QT_VER=	3
USE_GMAKE=	yes
PLIST=		${WRKDIR}/pkg-plist
MAKE_ENV=	QTDIR="${QTDIR}" MAKE="${GMAKE}" \
		QMAKESPEC="${LOCALBASE}/share/qt/mkspecs/freebsd-g++"
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's:RS_SYSTEM->getAppDir()+"/bin":"${PREFIX}/bin":' \
		-e 's:RS_SYSTEM->getDocPath() + "/qcaddoc.adp":"${DOCSDIR}/qcaddoc.adp":' \
		${WRKSRC}/qcad/src/qc_applicationwindow.cpp
	${REINPLACE_CMD} -e 's,MAKE=gmake,MAKE="gmake ${_MAKE_JOBS}",' \
		${WRKSRC}/scripts/build_qcad.sh

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
	@${ECHO_CMD} '@unexec ${RMDIR} %D/share/qcad 2> /dev/null || true' >> ${PLIST}

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
