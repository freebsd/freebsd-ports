# New ports collection makefile for:	dboxfe
# Date created:		2007-12-08
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	dboxfe
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A Qt4 front-end to DOSBox

RUN_DEPENDS=	dosbox:${PORTSDIR}/emulators/dosbox

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui network xml uic_build moc_build qmake_build rcc_build
HAS_CONFIGURE=	yes

PLIST_FILES=	bin/dboxfe bin/dboxfetray

.include <bsd.port.pre.mk>

PRO_DIRS=	. dboxfetray

do-configure:
.for dir in ${PRO_DIRS}
	@(cd ${WRKSRC}/${dir} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE})
.endfor

post-configure:
.for dir in ${PRO_DIRS}
	@${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; \
		 s|^CXX .*|CXX=${CXX}|; \
		 s|^LINK .*|LINK=${CXX}|' \
		${WRKSRC}/${dir}/Makefile
.endfor

do-build:
.for dir in ${PRO_DIRS}
	@(cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${MAKE})
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dboxfe ${PREFIX}/bin/dboxfe
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dboxfetray ${PREFIX}/bin/dboxfetray

.include <bsd.port.post.mk>
