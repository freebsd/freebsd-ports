# New ports collection makefile for:    cdrdao
# Date created:         7 April 1999
# Whom:                 futatuki
#
# $FreeBSD$
#

PORTNAME=	cdrdao
PORTVERSION=	1.1.7
PORTREVISION=	1
CATEGORIES=	sysutils audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	marius@alchemy.franken.de

.if defined(WITH_TOC2MP3)
LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame
.endif

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		cdrdao.1

.include <bsd.port.pre.mk>

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--with-gtkmm-prefix=${NONEXISTENT}

.if exists(${LOCALBASE}/bin/antlr) && exists(${LOCALBASE}/bin/dlg)
CONFIGURE_ARGS+=	--with-pcctsbin=${LOCALBASE}/bin \
			--with-pcctsinc=${LOCALBASE}/include/pccts
.endif

.if defined(WITHOUT_SCGLIB) && ${OSVERSION} > 300000
CONFIGURE_ARGS+=	--without-scglib
.endif

.if ${OSVERSION} <= 320000 || ${MACHINE_ARCH} == "sparc64" || \
	!defined(WITH_PTHREADS)
CONFIGURE_ARGS+=	--without-posix-threads
.endif

.if defined(WITH_TOC2MP3)
CONFIGURE_ARGS+=	--with-lame-include=${LOCALBASE}/include \
			--with-lame-lib=${LOCALBASE}/lib
PLIST_SUB=		TOC2MP3=""
.else
CONFIGURE_ARGS+=	--without-lame
PLIST_SUB=		TOC2MP3="@comment "
.endif

pre-everything:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITHOUT_SCGLIB=yes	builds without Joerg Schilling's SCSI library"
	@${ECHO_MSG} "WITH_PTHREADS=yes	enables usage of POSIX threads for the ring buffers"
	@${ECHO_MSG} "WITH_TOC2MP3=yes	builds toc2mp3 (requires audio/lame)"
	@${ECHO_MSG} ""

post-extract:
.if ${MACHINE_ARCH} == "alpha" || ${MACHINE_ARCH} == "sparc64"
	@(cd ${WRKSRC}/scsilib/RULES; \
	  ${LN} -sf i386-freebsd-cc.rul ${MACHINE_ARCH}-freebsd-cc.rul)
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|g; \
		s|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dao/cdrdao ${PREFIX}/bin/cdrdao
	@${INSTALL_PROGRAM} ${WRKSRC}/utils/toc2cue ${PREFIX}/bin/toc2cue
.if defined(WITH_TOC2MP3)
	@${INSTALL_PROGRAM} ${WRKSRC}/utils/toc2mp3 ${PREFIX}/bin/toc2mp3
.endif
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/dao/cdrdao.drivers ${DATADIR}/drivers
	@${INSTALL_MAN} ${WRKSRC}/dao/cdrdao.man ${PREFIX}/man/man1/cdrdao.1

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in CREDITS INSTALL README README.PlexDAE \
	Release-1.1.0 Release-1.1.2 Release-1.1.3 Release-1.1.4 \
	Release-1.1.5 Release-1.1.6 Release-1.1.7
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
