# New ports collection makefile for:	ghostscript
# Date created:		14 Jan 2002
# Whom:			Mita Yoshio <mita@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ghostscript
PORTVERSION=	6.52
CATEGORIES=	korean print
MASTER_SITES=	# nonexistent
PKGNAMESUFFIX=	-gnu-cjk
DISTNAME=	# nonexistent
DISTFILES=	# empty

MAINTAINER=	mita@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/Resource/cid.sh:${PORTSDIR}/print/ghostscript-gnu-cjk \
		${LOCALBASE}/share/ghostscript/fonts/Munhwa-Bold:${PORTSDIR}/korean/munhwafonts-cid

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

GSLIB_DIR=	${PREFIX}/share/ghostscript/${PORTVERSION}/lib
PLIST_SUB=	GS_VERSION=${PORTVERSION}
FONTS=		Munhwa-Bold Munhwa-Regular \
		MunhwaGothic-Bold MunhwaGothic-Regular

do-install:
.for i in ${FONTS}
	${LN} -sf ${PREFIX}/share/ghostscript/fonts/${i} \
		${PREFIX}/share/ghostscript/Resource/CIDFont/
.endfor
	${INSTALL_DATA} ${FILESDIR}/CIDFnmap.ko ${GSLIB_DIR}
	${MV} ${GSLIB_DIR}/CIDFnmap  ${GSLIB_DIR}/CIDFnmap.orig.ko
	${GREP} -v -e "CIDFnmap.ko" ${GSLIB_DIR}/CIDFnmap.orig.ko > \
		${GSLIB_DIR}/CIDFnmap
	${ECHO} '(CIDFnmap.ko) .runlibfile' >> ${GSLIB_DIR}/CIDFnmap

.include <bsd.port.mk>
