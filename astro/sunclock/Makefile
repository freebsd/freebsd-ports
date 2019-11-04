# Created by: torstenb
# $FreeBSD$

PORTNAME=	sunclock
PORTVERSION=	3.57
PORTREVISION=	1
CATEGORIES=	astro x11-clocks
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shows which portion of the Earth's surface is illuminated by the Sun

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		jpeg xorg
USE_XORG=	xpm

CPPFLAGS+=	$$(libpng-config --I_opts) \
		-I${LOCALBASE}/include \
		-DEMXBINDIR=\\\"${PREFIX}/bin\\\" \
		-DDOCDIR=\\\"${PREFIX}/lib/X11/doc\\\"
LDFLAGS+=	$$(libpng-config --L_opts) \
		-L${LOCALBASE}/lib

post-patch:
	@cd ${WRKSRC} && ${SED} -e \
		'/^DESTDIR/s|=.*|=${PREFIX}| ; \
		 s|/X11R6/man|$$(DESTDIR)/man| ; \
		 s|bin/X11|bin| ; \
		 s|^CC=|CC?=| ; \
		 s|^CFLAGS=|CFLAGS+=| ; \
		 s|-I/usr/include/X11|$${CPPFLAGS}| ; \
		 s|-L/usr/X11R6/lib|$${LDFLAGS}| ; \
		 s| make | $$(MAKE) | ; \
		 s|$$(SHAREDIR)/bin|$$(DESTDIR)/bin| ; \
		 s|$$(SHAREDIR)/editkit|$$(DESTDIR)/share/sunclock/editkit|' \
			< Makefile.noimake > Makefile
	@${LN} -sf sunclock.man ${WRKSRC}/sunclock.1
	@${REINPLACE_CMD} -e \
		's|= -O2|+= $${CPPFLAGS}| ; \
		 s|-L/usr/X11R6/lib|$${LDFLAGS}| ; \
		 s|gcc |$$(CC) |' ${WRKSRC}/editkit/Makefile.kit
	@${LN} -sf rc.example ${WRKSRC}/editkit/emxrc
	@${REINPLACE_CMD} -e \
		's|gzFile \* fd;|gzFile fd;|' ${WRKSRC}/readvmf.c

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} sunclock \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} sunclock.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} Sunclockrc \
		${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DATADIR}/earthmaps/vmf
	(cd ${WRKSRC}/vmf && ${INSTALL_DATA} *.vmf \
		${STAGEDIR}${DATADIR}/earthmaps/vmf)
	@${GZIP_CMD} ${STAGEDIR}${DATADIR}/earthmaps/vmf/*.vmf
	@${MKDIR} ${STAGEDIR}${DATADIR}/i18n
	(cd ${WRKSRC}/i18n && ${INSTALL_DATA} Sunclock.?? \
		${STAGEDIR}${DATADIR}/i18n)
	(cd ${WRKSRC}/editkit && ${INSTALL_PROGRAM} emx \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DATADIR}/editkit
	(cd ${WRKSRC}/editkit && ${INSTALL_DATA} MANUAL.emacs README emxrc \
		${STAGEDIR}${DATADIR}/editkit)

.include <bsd.port.mk>
