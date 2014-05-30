# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	kaistfonts-ksc
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	korean x11-fonts
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/
DISTNAME=	${PKGNAME}
DISTFILES=	kaist-newmj18.bdf.gz ks_philgi16.bdf.gz \
		kaist-newmj16.bdf.gz ks_iyagi16.bdf.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 KAIST font(ksc5601.1987-0 encoding) collection

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USES=		gmake
NO_WRKSUBDIR=	yes
MAKE_ENV=	DISTDIR=${DISTDIR} DISTFILES="${DISTFILES}"

do-extract:
	@${RM} -fr ${WRKDIR} && \
	${MKDIR} ${WRKDIR} && \
	cd ${WRKDIR} && \
	for file in ${DISTFILES}; do \
		${GUNZIP_CMD} -c < ${_DISTDIR}/$$file > `${ECHO_CMD} $$file | ${SED} -e 's/\.Z//' -e 's/\.gz//'`; \
	done

.include <bsd.port.mk>
