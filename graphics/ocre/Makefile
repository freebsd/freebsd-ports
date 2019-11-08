# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ocre
PORTVERSION=	0.043
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://lem.eui.upm.es/pub/ocre/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/./_/}

MAINTAINER=	w.schwarzenfeld@utanet.at
COMMENT=	Simple optical character recognition solution

BROKEN=		unfetchable

LICENSE=	GPLv3

LIB_DEPENDS=	libaspell.so:textproc/aspell
RUN_DEPENDS=	display:graphics/ImageMagick6 \
		gnuplot:math/gnuplot \
		ispell:textproc/aspell-ispell

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}

USES=		compiler:c11 gettext gmake gnome pkgconfig tar:tgz
USE_GNOME=	gtk20
MAKE_ARGS=	CC="${CC}" CFLAGS1="${CFLAGS}"

post-extract:
	@cd ${WRKSRC} && ${TAR} --exclude "*.orig" -xof ocre-decsWood-${PORTVERSION}.tgz

post-patch:
	@${REINPLACE_CMD} -e 's|, sys_nerr||' ${WRKSRC}/src/errors.c
	@${FIND} ${WRKSRC} -name "*.[1ch]" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|/usr/bin|${PREFIX}/bin|g ; \
		 s|/usr/share/locale|${PREFIX}/share/locale|g ; \
		 s|/usr/share/ocre|${DATADIR}|g'

do-configure:
	@${ECHO_CMD} -n > ${WRKSRC}/ddepend

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/es/man1
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}-es.1 ${STAGEDIR}${MAN1PREFIX}/man/es/man1/${PORTNAME}.1
	${INSTALL_DATA} ${WRKSRC}/po/es.mo ${STAGEDIR}${PREFIX}/share/locale/es/LC_MESSAGES/${PORTNAME}.mo
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for dir in conv decsWood decsWoodCur decsWoodCyrillic decsWoodLatin decsWoodLatinW
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR})
.endfor

.include <bsd.port.mk>
