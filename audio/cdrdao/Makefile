# New ports collection makefile for:    cdrdao
# Date created:         7 April 1999
# Whom:                 futatuki
#
# $FreeBSD$
#

PORTNAME=	cdrdao
PORTVERSION=	1.1.7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Write audio CD-Rs in disk-at-once mode

BUILD_DEPENDS=	antlr:${PORTSDIR}/devel/pccts \
		dlg:${PORTSDIR}/devel/pccts

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		cdrdao.1

.include <bsd.port.pre.mk>

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-lame=no \
		--with-gtkmm-prefix=${NONEXISTENT} \
		--with-pcctsbin=${LOCALBASE}/bin \
		--with-pcctsinc=${LOCALBASE}/include/pccts

.if defined(WITHOUT_SCGLIB) && ${OSVERSION} > 300000
CONFIGURE_ARGS+=	--without-scglib
.endif

.if !defined(WITH_PTHREADS) && ${OSVERSION} > 320000
CONFIGURE_ARGS+=	--without-posix-threads
.endif

pre-everything:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you don't want to use Joerg Schilling's SCSI library,"
	@${ECHO_MSG} "set WITHOUT_SCGLIB=yes."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you want to use pthreads, set WITH_PTHREADS=yes."
	@${ECHO_MSG} ""

post-extract:
.if ${MACHINE_ARCH} == "alpha"
	@(cd ${WRKSRC}/scsilib/RULES; \
	  ${LN} -sf i386-freebsd-cc.rul alpha-freebsd-cc.rul)
.endif
	@${CP} ${FILESDIR}/getopt.h ${WRKSRC}/utils

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
.for i in cdrdao toc2cue
	@${STRIP_CMD} ${PREFIX}/bin/${i}
.endfor
	@${MKDIR} ${DOCSDIR}
.for i in CREDITS INSTALL README README.FreeBSD README.PlexDAE \
	Release-1.1.0 Release-1.1.2 Release-1.1.3 Release-1.1.4 \
	Release-1.1.5 Release-1.1.6 Release-1.1.7
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
