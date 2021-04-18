# Created by: Arjan van Leeuwen <avleeuwen@piwebs.com>

PORTNAME=	dcraw
PORTVERSION=	9.28
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Decoder for RAW files from digital cameras

LICENSE=	GPLv2+

LIB_DEPENDS=	libjasper.so:graphics/jasper \
		liblcms2.so:graphics/lcms2

USES=		jpeg localbase tar:xz

CPPFLAGS+=	-I${LOCALBASE}/include/jasper
LIBS+=		-ljasper -ljpeg -llcms2 -lm

PLIST_FILES=	bin/dcraw \
		share/man/man1/dcraw.1.gz

do-build:
	@cd ${WRKSRC}/ && ${CC} -o dcraw ${CPPFLAGS} ${CFLAGS} dcraw.c ${LDFLAGS} ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dcraw ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/dcraw.1 ${STAGEDIR}${PREFIX}/share/man/man1/

# maintainer section:

MS_DIFF=	${MS_WRKSRC}/dcraw.c.diff
MS_VERSION=	`${CAT} ${MS_VERSIONFILE}`
MS_VERSIONFILE=	${MS_WRKSRC}/.version
MS_WRKSRC=	${WRKSRC}/tmp
MS_MASTER_SITE=	https://www.cybercom.net/~dcoffin/dcraw/
MS_DISTFILES=	dcraw.1 dcraw.c

maketar: do-clean extract
	@${MKDIR} ${MS_WRKSRC}/
.for file in ${MS_DISTFILES}
	@${FETCH_CMD} -o ${MS_WRKSRC}/${file} ${MS_MASTER_SITE}${file}
.endfor
	@${GREP} '^#define DCRAW_VERSION' ${MS_WRKSRC}/dcraw.c | cut -d'"' -f2 > ${MS_VERSIONFILE}
	@${MKDIR} -m 755 ${MS_WRKSRC}/dcraw-${MS_VERSION}/
	@cd ${MS_WRKSRC}/ && ${CHMOD} 644 ${MS_DISTFILES} && ${MV} ${MS_DISTFILES} dcraw-${MS_VERSION}/
	@(${DIFF} -u ${WRKSRC}/dcraw.c ${MS_WRKSRC}/dcraw-${MS_VERSION}/dcraw.c > ${MS_DIFF}) || ${TRUE}
	@if [ -s ${MS_DIFF} ]; then \
		cd ${MS_WRKSRC}/ && ${TAR} -Jcf dcraw-${MS_VERSION}.tar.xz dcraw-${MS_VERSION}/; \
		sudo ${INSTALL} -m 644 ${MS_WRKSRC}/dcraw-${MS_VERSION}.tar.xz ${DISTDIR}/; \
		${SED} -i '' -e '/^PORTVERSION=/ s|${PORTVERSION}|'${MS_VERSION}'|; /^PORTREVISION=/d' ${.CURDIR}/Makefile; \
		cd ${.CURDIR}/ && ${MAKE_CMD} makesum; \
		${ECHO_MSG} "*** Update from ${PORTVERSION} to ${MS_VERSION}, diff: ${MS_DIFF} ***"; \
	else \
		${ECHO_MSG} "*** ${MS_MASTER_SITE}dcraw.c is unchanged (${PORTVERSION}) ***"; \
	fi

.include <bsd.port.mk>
