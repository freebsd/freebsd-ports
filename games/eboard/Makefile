# New ports collection makefile for:	eboard
# Date created:				22 June 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	eboard
PORTVERSION=	0.8.0
EXTRASVERSION=	1pl2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} eboard-extras-${EXTRASVERSION}.tar.gz

MAINTAINER=	petef@FreeBSD.org
COMMENT=	GTK+ chess board interface (mainly for FICS and chessd)

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
USE_GNOME=	imlib
USE_REINPLACE=	yes
USE_X_PREFIX=	yes

INSTALL_TARGET=	install install-man

MAN1=	eboard-config.1 eboard-addtheme.1
MAN6=	eboard.6

post-patch:
	@${REINPLACE_CMD} -e 's,-O6,,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,po intl,po,' -e 's,CXXFLAGS =,CXXFLAGS +=,' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.for file in Crafty.txt FICS-Timeseal.txt GNUChess4.txt GNUChess5.txt \
	Scripts.txt Sjeng.txt Themes.txt
	${INSTALL_DATA} ${WRKSRC}/Documentation/${file} ${DOCSDIR}
.endfor
.endif
	${INSTALL_DATA} ${WRKDIR}/eboard-extras-${EXTRASVERSION}/*.png \
		${PREFIX}/share/eboard
	${INSTALL_DATA} ${WRKDIR}/eboard-extras-${EXTRASVERSION}/*.wav \
		${PREFIX}/share/eboard
	@${CAT} ${WRKDIR}/eboard-extras-${EXTRASVERSION}/extras1.conf >> \
		${PREFIX}/share/eboard/eboard_themes.conf

.include <bsd.port.mk>
