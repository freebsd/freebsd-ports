# New ports collection makefile for:	iiimf-le-xcin
# Date created:		2004-09-09
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	iiimf-le-xcin
PORTVERSION=	0.1.7
PORTREVISION=	5
CATEGORIES=	chinese textproc
MASTER_SITES=	http://people.redhat.com/llch/iiimf-xcin/${PORTVERSION}/
EXTRACT_SUFX=	-11.src.rpm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IIIMF xcin language engine, a traditional Chinese input method

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio
RUN_DEPENDS=	iiimd:${PORTSDIR}/textproc/iiimf-server

BROKEN=		does not build

USE_XORG=	x11 xproto
WRKSRC=		${WRKDIR}/iiimf-xcin
USE_BZIP2=	yes
USE_GNOME=	libxml2
USE_AUTOTOOLS=	automake:19 autoheader:262 autoconf:262 libtool:22
AUTOMAKE_ARGS=	--add-missing

do-extract:
	${MKDIR} ${WRKDIR}
	cd ${WRKDIR} && \
	${LOCALBASE}/bin/rpm2cpio.pl ${DISTDIR}/${DISTFILES} | \
	${CPIO} -iud
	cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
	${WRKDIR}/${DISTNAME}.tar.bz2 ${EXTRACT_AFTER_ARGS}

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/iiim,g" \
		${WRKSRC}/acfiles/im_common.m4 \
		${WRKSRC}/src/cin2tab/constant.h \
		${WRKSRC}/src/xmlconf.c \
		${WRKSRC}/xcin.xml.conf

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal -I acfiles

.include <bsd.port.mk>
