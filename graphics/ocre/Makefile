# New ports collection makefile for:	ocre
# Date created:		11 June 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ocre
PORTVERSION=	0.028
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://lem.eui.upm.es/pub/ocre/ CENKES
DISTNAME=	${PORTNAME}_v${DISTVERSION:S/./_/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple optical character recognition solution

LIB_DEPENDS=	aspell.16:${PORTSDIR}/textproc/aspell
RUN_DEPENDS=	display:${PORTSDIR}/graphics/ImageMagick \
		ispell:${PORTSDIR}/textproc/ispell \
		gnuplot:${PORTSDIR}/math/gnuplot

USE_GETTEXT=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/v${DISTVERSION}
MAN1=		${PORTNAME}.1
MANLANG=	"" es

post-patch:
	@${GREP} -rl /usr/share ${WRKSRC}|${XARGS} ${REINPLACE_CMD} -e\
		's|/usr/share/ocre|${DATADIR}|;s|/usr/share/locale|${PREFIX}/share/locale|'
	@${GREP} -rl DESTDIR ${WRKSRC}|${XARGS} ${REINPLACE_CMD} -e\
		'/^DESTDIR/s|/usr|${PREFIX}|'
	@${GREP} -rl /usr/bin ${WRKSRC}|${XARGS} ${REINPLACE_CMD} -e\
		's|/usr/bin|${LOCALBASE}/bin|'
	@${REINPLACE_CMD} -Ee 's|/usr/include|${LOCALBASE}/include|g;\
		s|/usr/lib/([a-z0-9.-]+)/include|${LOCALBASE}/include/\1|g;\
		s|opcionesp.h||'\
		${WRKSRC}/ddepend
	@${REINPLACE_CMD} -e 's|, sys_nerr||' ${WRKSRC}/src/errors.c
	@${REINPLACE_CMD} -e 's|gcc|${CC}|;s|-O2|${CFLAGS}|' ${WRKSRC}/Makefile

do-install:
	@${INSTALL} -d ${DATADIR}/
	@${INSTALL} -d ${MAN1PREFIX}/man/es/man1/
	@${TAR} xof ${WRKSRC}/ocre-decsWood-${DISTVERSION}.tgz -C ${DATADIR}/
	@${CHMOD} -h 755 ${DATADIR}/decsWood
	@${INSTALL_PROGRAM} ${WRKSRC}/ocre ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/ocre.1 ${MAN1PREFIX}/man/man1/
	@${INSTALL_MAN} ${WRKSRC}/ocre-es.1 ${MAN1PREFIX}/man/es/man1/ocre.1
	@${INSTALL_DATA} ${WRKSRC}/po/es.mo ${PREFIX}/share/locale/es/LC_MESSAGES/ocre.mo

.include <bsd.port.mk>
