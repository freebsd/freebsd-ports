# New ports collection makefile for:	znibbles
# Date created:		21 Aug 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	znibbles
PORTVERSION=	0.0.7
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://old.koalateam.com/ftp/pub/games/znibbles/ \
		http://www.jfouffa.com/vmallet/archives/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multi-player networked nibbles game

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

OPTIONS=	GTK "Build GTK+ client" on

USE_MOTIF=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN6=		nibbles.6 znibbles.6 znibblesX.6
PLIST_FILES=	bin/nibbles bin/znibbles bin/znibblesX

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GTK)
CONFIGURE_ARGS+=--disable-gtk
.else
USE_GNOME+=	gtk12
MAN6+=		gznibbles.6
PLIST_FILES+=	bin/gznibbles
.endif

post-extract:
	@${RM} -f ${WRKSRC}/src/getopt.h
#	@${LN} -sf /usr/include/getopt.h ${WRKSRC}/src

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|doc||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^getopt/d ; \
		 s|getopt.[cho]||g ; \
		 s|getopt1.[co]||g' ${WRKSRC}/src/Makefile.in
.for dir in GTK Motif X11
	@${REINPLACE_CMD} -e \
		's|../getopt.h||g' ${WRKSRC}/src/${dir}/Makefile.in
.endfor

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/nibbles.6 ${MAN6PREFIX}/man/man6
	${INSTALL_MAN} ${WRKSRC}/doc/znibbles.6 ${MAN6PREFIX}/man/man6
	${INSTALL_MAN} ${WRKSRC}/doc/znibblesX.6 ${MAN6PREFIX}/man/man6
.if !defined(WITHOUT_GTK)
	${INSTALL_MAN} ${WRKSRC}/doc/gznibbles.6 ${MAN6PREFIX}/man/man6
.endif

.include <bsd.port.post.mk>
