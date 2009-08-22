# New ports collection makefile for:	mopac
# Date created:				1997-04-23
# Whom:					Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	mopac
PORTVERSION=	7.${MOPAC_SUBVERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	SF/${PORTNAME}7/${PORTNAME}7/${PORTNAME}7-1.10
DISTNAME=	mopac7-${MOPAC_SUBVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Semi-empirical (MNDO, etc.) molecular orbital calculation

BUILD_DEPENDS=	f2c:${PORTSDIR}/lang/f2c
LIB_DEPENDS=	f2c:${PORTSDIR}/lang/f2c

MOPAC_SUBVERSION=	1.10
WRKSRC=		${WRKDIR}/mopac7-${MOPAC_SUBVERSION}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"
CFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e \
		"s,pkgconfigdir = .*,pkgconfigdir = $$\{exec_prefix\}/libdata/pkgconfig," \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run_mopac7  ${PREFIX}/bin/mopac7
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/test
	${INSTALL_DATA} ${WRKSRC}/tests/*dat ${EXAMPLESDIR}/test
	${INSTALL_DATA} ${WRKSRC}/tests/*OUT ${EXAMPLESDIR}/test
.endif

.include <bsd.port.mk>
