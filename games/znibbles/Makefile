# Created by: Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	znibbles
PORTVERSION=	0.0.7
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://old.koalateam.com/ftp/pub/games/znibbles/ \
		http://www.jfouffa.com/vmallet/archives/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-player networked nibbles game

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	GTK1
OPTIONS_DEFAULT=	GTK1

USES=		motif
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/nibbles bin/znibbles bin/znibblesX \
		man/man6/nibbles.6.gz man/man6/znibbles.6.gz \
		man/man6/znibblesX.6.gz

GTK1_USE=		GNOME=gtk12
GTK1_PLIST_FILES=	bin/gznibbles man/man6/gznibbles.6.gz
GTK1_CONFIGURE_ENABLE=	gtk

post-extract:
	@${RM} -f ${WRKSRC}/src/getopt.h

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
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} nibbles.6 znibbles.6 znibblesX.6 \
		gznibbles.6 ${STAGEDIR}${MAN6PREFIX}/man/man6)

.include <bsd.port.mk>
