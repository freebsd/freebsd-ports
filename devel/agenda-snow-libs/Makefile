# New ports collection makefile for:	agenda-snow-libs
# Date created:		20 October 2001
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	agenda-snow-libs
PORTVERSION=	1.2.0
CATEGORIES=	devel
MASTER_SITES=	http://lev.serebryakov.spb.ru/download/agenda/

MAINTAINER=	lev@FreeBSD.org
COMMENT=	SNOW libraries which are needed to develop for Agenda VR3 PDA

RUN_DEPENDS=	${PREFIX}/${TARGET_PLATFORM}/include/stdio.h:${PORTSDIR}/devel/agenda-headers

USE_BZIP2=	yes

TARGET_PLATFORM=mipsel-linux
SUBSTS=		LOCALBASE=${LOCALBASE} TARGET_PLATFORM=${TARGET_PLATFORM}
TRANSFORM_FILES=	mipsel-linux/etc/config.site \
			mipsel-linux/etc/vrpbuild.conf \
			bin/mksnow \
			bin/snow-make-ldscript \
			bin/snow-makesyms \
			bin/snow-mklibrary \
			bin/snow-specs-verify

do-build:
.for F in ${TRANSFORM_FILES}
	@${CP} ${WRKSRC}/${F} ${WRKSRC}/${F}.new
	@${SED} ${SUBSTS:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} < ${WRKSRC}/${F}.new > ${WRKSRC}/${F}
	@${RM} ${WRKSRC}/${F}.new
.endfor

do-install:
	(cd ${WRKSRC} && tar -cf - *) | (cd ${PREFIX} && tar xf -)

.include <bsd.port.mk>
