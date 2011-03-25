# New ports collection makefile for:	ocre
# Date created:		11 June 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ocre
PORTVERSION=	0.034
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://lem.eui.upm.es/pub/ocre/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple optical character recognition solution

LIB_DEPENDS=	aspell.16:${PORTSDIR}/textproc/aspell
RUN_DEPENDS=	display:${PORTSDIR}/graphics/ImageMagick \
		gnuplot:${PORTSDIR}/math/gnuplot \
		ispell:${PORTSDIR}/textproc/ispell

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}

USE_GNOME=	gtk20
USE_GETTEXT=	yes
USE_GMAKE=	yes
MAKE_ENV=	CFLAGS1="${CFLAGS}"

MANLANG=	"" es
MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's|^CC =|CC ?=|g ; \
		 s|^CFLAGS1=|CFLAGS1 ?=| ; \
		 s|-O2||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|, sys_nerr||' ${WRKSRC}/src/errors.c
	@${FIND} ${WRKSRC} -name "*.[1ch]" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|/usr/bin|${PREFIX}/bin|g ; \
		 s|/usr/share/locale|${PREFIX}/share/locale|g ; \
		 s|/usr/share/ocre|${DATADIR}|g'

do-configure:
	@${ECHO_CMD} -n > ${WRKSRC}/ddepend

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
	@${MKDIR} ${MAN1PREFIX}/man/es/man1
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}-es.1 ${MAN1PREFIX}/man/es/man1/${PORTNAME}.1
	${INSTALL_DATA} ${WRKSRC}/po/es.mo ${PREFIX}/share/locale/es/LC_MESSAGES/${PORTNAME}.mo
	@${MKDIR} ${DATADIR}
	@${TAR} --exclude "*.orig" -xof ${WRKSRC}/ocre-decsWood-${PORTVERSION}.tgz -C ${DATADIR}
	@${CHMOD} -h 755 ${DATADIR}/decsWood

.include <bsd.port.mk>
