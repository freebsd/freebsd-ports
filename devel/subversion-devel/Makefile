# New ports collection makefile for:	subversion
# Date created:				10 September 2001
# Whom:					rooneg@electricjellyfish.net
#
# $FreeBSD$

PORTNAME=	subversion
PORTVERSION=	r3033	# 0.14.2
CATEGORIES=	devel
MASTER_SITES=	http://subversion.tigris.org/files/documents/15/718/

MAINTAINER=	rooneg@electricjellyfish.net

LIB_DEPENDS=	db4:${PORTSDIR}/databases/db4 \
		neon.22:${PORTSDIR}/www/neon \
		expat.4:${PORTSDIR}/textproc/expat2 \
		apr:${PORTSDIR}/devel/apr
RUN_DEPENDS=	gdiff3:${PORTSDIR}/textproc/diffutils
BUILD_DEPENDS=	gdiff3:${PORTSDIR}/textproc/diffutils

WRKSRC=	${WRKDIR}/subversion-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS= --with-ssl \
		--with-neon=${LOCALBASE} \
		--with-berkeley-db=${LOCALBASE}/include/db4:${LOCALBASE}/lib \
		--with-apr=${LOCALBASE} \
		--with-apr-util=${LOCALBASE}

post-extract:
	@${REINPLACE_CMD} 's/ldb/ldb4/g' ${WRKSRC}/configure

	@${RM} -r ${WRKSRC}/neon
	@${RM} -r ${WRKSRC}/apr
	@${RM} -r ${WRKSRC}/apr-util

post-configure:
	@${REINPLACE_CMD} 's/install-swig-py-lib//g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's/swig-py-lib//g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's/install-man install-info//g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
