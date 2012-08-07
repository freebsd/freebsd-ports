# New ports collection makefile for:	dcraw
# Date created: 			14 February 2004
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	dcraw
PORTVERSION=	9.16
CATEGORIES=	graphics
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Decoder for RAW files from digital cameras

LIB_DEPENDS=	jasper:${PORTSDIR}/graphics/jasper \
		jpeg:${PORTSDIR}/graphics/jpeg \
		lcms:${PORTSDIR}/graphics/lcms

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/jasper
LDFLAGS+=	-L${LOCALBASE}/lib -lm -ljasper -ljpeg -llcms
USE_XZ=		yes

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

do-build:
	cd ${WRKSRC}/ && ${CC} -o ${PORTNAME} ${CFLAGS} ${PORTNAME}.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1/

# maintainer section:

MS_DIFF=	${MS_WRKSRC}/${PORTNAME}.c.diff
MS_VERSION=	`${CAT} ${MS_VERSIONFILE}`
MS_VERSIONFILE=	${MS_WRKSRC}/.version
MS_WRKSRC=	${WRKSRC}/tmp
MS_MASTER_SITE=	http://www.cybercom.net/~dcoffin/${PORTNAME}/
MS_DISTFILES=	${PORTNAME}.1 ${PORTNAME}.c

maketar: do-clean extract
	${MKDIR} ${MS_WRKSRC}/
.for file in ${MS_DISTFILES}
	${FETCH_CMD} -o ${MS_WRKSRC}/${file} ${MS_MASTER_SITE}${file}
.endfor
	${GREP} '^#define DCRAW_VERSION' ${MS_WRKSRC}/dcraw.c | cut -d'"' -f2 > ${MS_VERSIONFILE}
	${MKDIR} ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}/
	cd ${MS_WRKSRC}/ && ${MV} ${MS_DISTFILES} ${PORTNAME}-${MS_VERSION}/
	(${DIFF} -u ${WRKSRC}/${PORTNAME}.c ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}/${PORTNAME}.c > ${MS_DIFF}) || ${TRUE}
	if [ -s ${MS_DIFF} ]; then \
		cd ${MS_WRKSRC}/ && ${TAR} -Jcf ${PORTNAME}-${MS_VERSION}.tar.xz ${PORTNAME}-${MS_VERSION}/; \
		${INSTALL} -m 644 ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}.tar.xz ${DISTDIR}/; \
		${SED} -i '' -e '/^PORTVERSION=/ s|${PORTVERSION}|'${MS_VERSION}'|; /^PORTREVISION=/d' ${.CURDIR}/Makefile; \
		cd ${.CURDIR}/ && ${MAKE} makesum; \
		${ECHO_MSG} "*** Update from ${PORTVERSION} to ${MS_VERSION}, diff: ${MS_DIFF} ***"; \
	else \
		${ECHO_MSG} "*** ${MS_MASTER_SITE}${PORTNAME}.c is unchanged (${PORTVERSION}) ***"; \
	fi

.include <bsd.port.mk>
