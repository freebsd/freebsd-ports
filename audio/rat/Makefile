# New ports collection makefile for:  rat
# Date created:			      3 July 1999
# Whom:				      O.Hodson@cs.ucl.ac.uk (Orion Hodson)
#
# $FreeBSD$
#

PORTNAME=	rat
PORTVERSION=	4.2.25
PORTREVISION=	4
CATEGORIES=	audio ipv6 tk mbone
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/rat/releases/${PORTVERSION}/ \
		http://www.icir.org/hodson/ucl-mirror/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IPv4/v6 Multicast and unicast audio conferencing tool

DEPRECATED=	Unmaintained, anachronistic, mail freebsd-ports@FreeBSD.org if interested
EXPIRATION=	2011-06-30

USE_TK=		yes
USE_XORG=	x11 xext sm ice
USE_AUTOTOOLS=	autoconf213
USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-ipv6

MAN1=		rat.1
MANCOMPRESSED=	no

RAT_BUILD_DIRS=	common rat
RAT=		${PORTNAME}-${PORTVERSION}
RAT_SCRIPT=	${PORTNAME}
PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--with-tcltk-version=${TK_VER}

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile: missing header
.endif

.if ${OSVERSION} >= 700011
EXTRA_PATCHES=	${FILESDIR}/timet.patch
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,-Werror,," \
		-e 's,^TCL_INC=$${PARENT}.*,TCL_INC=${TCL_INCLUDEDIR},g' \
		-e 's,^TCL_LIB=$${PARENT}.*,TCL_LIB=${LOCALBASE}/lib,g' \
		-e 's,^TK_INC=$${PARENT}.*,TK_INC=${TK_INCLUDEDIR},g' \
		-e 's,^TK_LIB=$${PARENT}.*,TK_LIB=${LOCALBASE}/lib,g' \
		${WRKSRC}/common/configure.in ${WRKSRC}/rat/configure.in

do-install:
	@${REINPLACE_CMD} 's|#/|#!/|' ${WRKSRC}/rat/${RAT_SCRIPT}
	${INSTALL_PROGRAM} ${WRKSRC}/rat/${RAT} ${PREFIX}/bin/${RAT}
	${INSTALL_PROGRAM} ${WRKSRC}/rat/${RAT}-ui ${PREFIX}/bin/${RAT}-ui
	${INSTALL_PROGRAM} ${WRKSRC}/rat/${RAT}-media ${PREFIX}/bin/${RAT}-media
	${INSTALL_SCRIPT} ${WRKSRC}/rat/${RAT_SCRIPT} ${PREFIX}/bin/${RAT_SCRIPT}
	${INSTALL_MAN}  ${WRKSRC}/rat/man/man1/rat.1 ${PREFIX}/man/man1
	${MKDIR} ${LOCALBASE}/etc/sdr/plugins
	${INSTALL_DATA} ${WRKSRC}/rat/sdr2.plugin.S02.audio.rtp.*.${RAT} ${LOCALBASE}/etc/sdr/plugins

pre-configure:
	cd ${WRKSRC}/common && ${AUTOCONF} && ./configure ${CONFIGURE_ARGS}
	cd ${WRKSRC}/common && ${GMAKE}

do-configure:
	cd ${WRKSRC}/rat && ${AUTOCONF} && ./configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC}/rat && ${GMAKE}

run-autotools::
	@${DO_NADA}

.include <bsd.port.post.mk>
