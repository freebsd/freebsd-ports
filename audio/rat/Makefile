# New ports collection makefile for:  rat
# Date created:			      3 July 1999
# Whom:				      O.Hodson@cs.ucl.ac.uk (Orion Hodson)
#
# $FreeBSD$
#

PORTNAME=	rat
PORTVERSION=	4.2.25
PORTREVISION=	2
CATEGORIES=	mbone audio ipv6 tk84
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/rat/releases/${PORTVERSION}/ \
		http://www.icir.org/hodson/ucl-mirror/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IPv4/v6 Multicast and unicast audio conferencing tool

USE_TK=		yes
USE_TK_BUILD=	yes
USE_TCL=	yes
USE_TCL_BUILD=	yes
USE_AUTOTOOLS=	autoconf:213
USE_GMAKE=	yes
CONFIGURE_ARGS=	--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include --enable-ipv6

MAN1=		rat.1
MANCOMPRESSED=	no

RAT_BUILD_DIRS=	common rat
RAT=		${PORTNAME}-${PORTVERSION}
RAT_SCRIPT=	${PORTNAME}
PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700011
EXTRA_PATCHES=	${FILESDIR}/timet.patch
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,-Werror,," ${WRKSRC}/common/configure.in \
		${WRKSRC}/rat/configure.in

do-install:
	@${REINPLACE_CMD} 's|#/|#!/|' ${WRKSRC}/rat/${RAT_SCRIPT}
	${INSTALL_PROGRAM} ${WRKSRC}/rat/${RAT} ${PREFIX}/bin/${RAT}
	${INSTALL_PROGRAM} ${WRKSRC}/rat/${RAT}-ui ${PREFIX}/bin/${RAT}-ui
	${INSTALL_PROGRAM} ${WRKSRC}/rat/${RAT}-media ${PREFIX}/bin/${RAT}-media
	${INSTALL_SCRIPT} ${WRKSRC}/rat/${RAT_SCRIPT} ${PREFIX}/bin/${RAT_SCRIPT}
	${INSTALL_MAN}  ${WRKSRC}/rat/man/man1/rat.1 ${PREFIX}/man/man1
	${MKDIR} ${LOCALBASE}/etc/sdr/plugins
	${INSTALL_DATA} ${WRKSRC}/rat/sdr2.plugin.S02.audio.rtp.*.${RAT} ${LOCALBASE}/etc/sdr/plugins

do-build:
	cd ${WRKSRC}/common/src && ${GMAKE}
	cd ${WRKSRC}/rat && ${GMAKE}

run-autotools::
	@${DO_NADA}

do-configure:
	cd ${WRKSRC}/common && ${AUTOCONF} && ./configure ${CONFIGURE_ARGS}
	cd ${WRKSRC}/rat && ${AUTOCONF} && ./configure ${CONFIGURE_ARGS} \
		--with-tcl=${LOCALBASE} --with-tk=${LOCALBASE} --with-tcltk-version=${TK_VER}

.include <bsd.port.post.mk>
