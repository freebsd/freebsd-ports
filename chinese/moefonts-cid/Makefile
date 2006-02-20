# New ports collection makefile for:	MOE CIDFonts
# Date created:		3 Mar 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	moefonts-cid
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	chinese print
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/statue/moefonts-cid/ \
		ftp://ftp.ora.com/pub/examples/nutshell/cjkv/adobe/ \
		ftp://ftp.ora.com/pub/examples/nutshell/cjkv/adobe/samples/
DISTFILES=	MOEKai-Regular MOESung-Regular
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MOE CIDFonts converted by Adobe

RUN_DEPENDS=	${ADOBECMAPDIR}/ai0/CMap/Identity-H:${PORTSDIR}/print/adobe-cmaps

USE_GHOSTSCRIPT_RUN=	yes
NO_BUILD=	YES
SUB_FILES=	pkg-install pkg-deinstall
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

ADOBECMAPDIR=   ${LOCALBASE}/share/fonts/adobe-cmaps

pre-fetch:
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

do-install:
	@${INSTALL_DATA} ${DISTDIR}/MOEKai-Regular \
		${DISTDIR}/MOESung-Regular \
		${FILESDIR}/MOEKai-Regular-ETen-B5-H.gsf \
		${FILESDIR}/MOEKai-Regular-ETen-B5-V.gsf \
		${FILESDIR}/MOESung-Regular-ETen-B5-H.gsf \
		${FILESDIR}/MOESung-Regular-ETen-B5-V.gsf \
		${PREFIX}/share/ghostscript/fonts
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
