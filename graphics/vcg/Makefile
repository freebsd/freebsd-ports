# New ports collection makefile for:	vcg
# Date created:		19 February 1995
# Whom:			hsu
#
# $FreeBSD$
#

PORTNAME=	vcg
PORTVERSION=	1.30
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.uni-sb.de/pub/graphics/vcg/
DISTNAME=	${PORTNAME}.20050204
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Visualization Tool for compiler graphs

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake

USE_XORG=	x11 xext
MANL=		pbmrot90.l pbmshift.l pbm2hp.l vcgdemomaker.l vcg.l xvcg.l

MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}

pre-patch:
	@${MKDIR} ${WRKSRC}/preconf/X11ccFreeBSD
.for file in conf demo.csh globals.h tMakefile
	@${SED} -e "s:%%CC%%:${CC}:g" \
	        -e "s:%%CFLAGS%%:${CFLAGS}:g" \
	        -e "s:%%MAKE%%:${MAKE}:g;" \
		-e "s:%%LOCALBASE%%:${LOCALBASE}:g" \
	        -e "s:%%PREFIX%%:${PREFIX}:g" \
	        -e "s:%%INSTALL_PROGRAM%%:${INSTALL_PROGRAM}:g" \
	        -e "s:%%INSTALL_MAN%%:${INSTALL_MAN}:g" \
		< ${FILESDIR}/${file} > ${WRKSRC}/preconf/X11ccFreeBSD/${file}
.endfor

.include <bsd.port.mk>
