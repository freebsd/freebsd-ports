# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	kaistfonts
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	korean x11-fonts
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/
PKGNAMESUFFIX=	-ksc
DISTNAME=	${PKGNAME}
DISTFILES=	kaist-newmj18.bdf.gz ks_philgi16.bdf.gz \
		kaist-newmj16.bdf.gz ks_iyagi16.bdf.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 KAIST font(ksc5601.1987-0 encoding) collection

SUB_FILES=	pkg-message

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

USES=		fonts gmake
NO_WRKSUBDIR=	yes
MAKE_ENV=	DISTDIR=${DISTDIR} DISTFILES="${DISTFILES}" FONTSDIR="${FONTSDIR}"

do-extract:
	@${RM} -fr ${WRKSRC} && \
	${MKDIR} ${WRKSRC} && \
	cd ${WRKSRC} && \
	for file in ${DISTFILES}; do \
		${GUNZIP_CMD} -c < ${_DISTDIR}/$$file > `${ECHO_CMD} $$file | ${SED} -e 's/\.Z//' -e 's/\.gz//'`; \
	done

.include <bsd.port.mk>
