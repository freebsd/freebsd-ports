# New ports collection makefile for:	MOE CIDFonts
# Date created:		3 Mar 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	moefonts-cid
PORTVERSION=	1.0
CATEGORIES=	chinese print
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/moefonts-cid/ \
				ftp://ftp.ora.com/pub/examples/nutshell/cjkv/adobe/ \
				ftp://ftp.ora.com/pub/examples/nutshell/cjkv/adobe/samples/
DISTFILES=	MOEKai-Regular MOESung-Regular ac13.tar.Z ag13.tar.Z

MAINTAINER=	keith@FreeBSD.org

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript6

NO_BUILD=	YES

do-extract:
	@${MKDIR} ${WRKDIR}
	@(cd ${WRKDIR} && \
	  ${TAR} xzf ${DISTDIR}/ac13.tar.Z && \
	  ${TAR} xzf ${DISTDIR}/ag13.tar.Z )

do-install:
	@${INSTALL_DATA} ${DISTDIR}/MOEKai-Regular \
		${DISTDIR}/MOESung-Regular \
		${FILESDIR}/MOEKai-Regular-ETen-B5-H.gsf \
		${FILESDIR}/MOEKai-Regular-ETen-B5-V.gsf \
		${FILESDIR}/MOESung-Regular-ETen-B5-H.gsf \
		${FILESDIR}/MOESung-Regular-ETen-B5-V.gsf \
		${PREFIX}/share/ghostscript/fonts
	@${MKDIR} ${PREFIX}/share/ghostscript/fonts/CMap
	@${INSTALL_DATA} ${WRKDIR}/ac13/CMap/* \
		${PREFIX}/share/ghostscript/fonts/CMap
	@${INSTALL_DATA} ${WRKDIR}/ag13/CMap/* \
		${PREFIX}/share/ghostscript/fonts/CMap
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
