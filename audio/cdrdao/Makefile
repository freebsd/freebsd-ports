# New ports collection makefile for:    cdrdao
# Date created:         7 April 1999
# Whom:                 futatuki
#
# $FreeBSD$
#

PORTNAME=	cdrdao
PORTVERSION=	1.1.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cdrdao
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	lebel@lebel.org

BUILD_DEPENDS=	antlr:${PORTSDIR}/devel/pccts \
		dlg:${PORTSDIR}/devel/pccts

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		cdrdao.1

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--disable-gtkmmtest --with-pcctsbin=${LOCALBASE}/bin \
		--with-pcctsinc=${LOCALBASE}/include/pccts

.if defined(WITHOUT_SCGLIB) && ${OSVERSION} > 300000
CONFIGURE_ARGS+=	--without-scglib
.endif

.if !defined(WITH_PTHREADS) && ${OSVERSION} > 320000
CONFIGURE_ARGS+=	--without-posix-threads
.endif

pre-fetch:
	@${ECHO_MSG} "If you don't want to use Joerg Schilling's SCSI library,"
	@${ECHO_MSG} "set WITHOUT_SCGLIB=yes."
	@${ECHO_MSG} "If you want to use pthreads, set WITH_PTHREADS=yes."

.if ${MACHINE_ARCH} == "alpha"
post-extract:
	@(cd ${WRKSRC}/scsilib/RULES; \
	  ${LN} -sf i386-freebsd-cc.rul alpha-freebsd-cc.rul)
.endif

post-install:
	strip ${PREFIX}/bin/cdrdao
	@${MKDIR} ${PREFIX}/share/doc/cdrdao
.for i in COPYING CREDITS INSTALL README README.FreeBSD README.PlexDAE \
	Release-1.1.0 Release-1.1.2 Release-1.1.3 Release-1.1.4
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/cdrdao/
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
