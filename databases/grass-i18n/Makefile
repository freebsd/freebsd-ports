# New ports collection makefile for:	grass
# Date created:		15 January 2000
# Whom:			reg
#
# $FreeBSD$
#

PORTNAME=	grass
PORTVERSION=	5.0b8
CATEGORIES=	databases
MASTER_SITES=	ftp://grass.baylor.edu/pub/grass/grass5.0beta/source/ \
		http://www.geog.uni-hannover.de/grass/grass5/source/
DISTNAME=	grass5.0beta8_src

MAINTAINER=	reg@FreeBSD.org

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.4:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg
BUILD_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80
RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tiff-includes=${LOCALBASE}/include \
		--with-tiff-libs=${LOCALBASE}/lib \
		--prefix=${WRKDIR}/grass5 \
		--with-bindir=${WRKDIR}/grass5/bin

WRKSRC=		${WRKDIR}

ALL_TARGET=	install

SED_FILES= \
		bin/gmake5 \
		bin/gmakelinks5 \
		bin/grass5 \
		dev/create_fifos.sh \
		etc/paint/driver.rsh \
		etc/monitorcap \
		scripts/create_fifos.sh

pre-configure:
	@${MKDIR} ${WRKDIR}/grass5/bin

do-install:
	${MKDIR} ${PREFIX}/grass5
	${CHMOD} 755 ${PREFIX}/grass5
	cd ${WRKDIR}/grass5 && ${TAR} -cf - * | \
		${TAR} -xpf - -C ${PREFIX}/grass5
.for F in ${SED_FILES}
	${SED} -e "s^${WRKDIR}^${PREFIX}^g" \
	  ${WRKDIR}/grass5/$F > ${PREFIX}/grass5/$F
.endfor

.include <bsd.port.mk>
