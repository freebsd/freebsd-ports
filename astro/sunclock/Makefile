# Created by: torstenb
# $FreeBSD$

PORTNAME=	sunclock
PORTVERSION=	3.57
CATEGORIES=	astro x11-clocks
MASTER_SITES=	http://www.arvernes.com/files/jpd/ \

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shows which portion of the Earth's surface is illuminated by the Sun

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_XORG=	xpm
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	$$(libpng-config --I_opts) \
		-I${LOCALBASE}/include \
		-DEMXBINDIR=\\\"${PREFIX}/bin\\\" \
		-DDOCDIR=\\\"${PREFIX}/lib/X11/doc\\\"
LDFLAGS+=	$$(libpng-config --L_opts) \
		-L${LOCALBASE}/lib

MAN1=		sunclock.1

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
	${INSTALL_PROGRAM} ${WRKSRC}/sunclock ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sunclock.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Sunclockrc ${DATADIR}
	@${MKDIR} ${DATADIR}/earthmaps/vmf
	${INSTALL_DATA} ${WRKSRC}/vmf/*.vmf ${DATADIR}/earthmaps/vmf
	@${GZIP_CMD} ${DATADIR}/earthmaps/vmf/*.vmf
	@${MKDIR} ${DATADIR}/i18n
	${INSTALL_DATA} ${WRKSRC}/i18n/Sunclock.?? ${DATADIR}/i18n
	${INSTALL_PROGRAM} ${WRKSRC}/editkit/emx ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/editkit
	${INSTALL_DATA} ${WRKSRC}/editkit/MANUAL.emacs ${DATADIR}/editkit
	${INSTALL_DATA} ${WRKSRC}/editkit/README ${DATADIR}/editkit
	${INSTALL_DATA} ${WRKSRC}/editkit/emxrc ${DATADIR}/editkit

.include <bsd.port.mk>
