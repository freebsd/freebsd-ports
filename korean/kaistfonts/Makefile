# New ports collection makefile for:	seri font collection
# Date created:		Fri Mar 27 17:26:42 KST 1998
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	kaistfonts-ksc
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	korean x11-fonts
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/
DISTNAME=	${PKGNAME}
DISTFILES=	kaist-newmj18.bdf.gz ks_philgi16.bdf.gz \
		kaist-newmj16.bdf.gz ks_iyagi16.bdf.gz

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	X11 KAIST font(ksc5601.1987-0 encoding) collection

USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

USE_GMAKE=	yes
NO_WRKSUBDIR=	yes
MAKE_ENV=	DISTDIR=${DISTDIR} DISTFILES="${DISTFILES}"

do-extract:
	@${RM} -fr ${WRKDIR} && \
	${MKDIR} ${WRKDIR} && \
	cd ${WRKDIR} && \
	for file in ${DISTFILES}; do \
		${GUNZIP_CMD} -c < ${_DISTDIR}/$$file > `${ECHO_CMD} $$file | ${SED} -e 's/\.Z//' -e 's/\.gz//'`; \
	done

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
