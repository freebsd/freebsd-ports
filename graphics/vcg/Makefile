# Created by: hsu
# $FreeBSD$

PORTNAME=	vcg
PORTVERSION=	1.30
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://download.polytechnic.edu.na/pub2/openpkg1/sources/DST/vcg/ \
		http://ftp.gwdg.de/linux/openpkg/openpkg-ftp/sources/DST/vcg/ \
		http://ftp.sjtu.edu.cn/sites/ftp.openpkg.org/sources/DST/vcg/ \
		ftp://ftp.cs.uni-sb.de/pub/graphics/vcg/
DISTNAME=	${PORTNAME}.20050204
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Visualization Tool for compiler graphs

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake

WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}

USE_XORG=	x11 xext
MAKE_JOBS_UNSAFE=	yes

MANL=		pbmrot90.l pbmshift.l pbm2hp.l vcgdemomaker.l vcg.l xvcg.l

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

post-patch:
.for i in animation1.c animation2.c animation3.c vcgcount.c
	@${REINPLACE_CMD} -e '/ main/s|^void|int|' ${WRKSRC}/demo/${i}
.endfor

.include <bsd.port.mk>
