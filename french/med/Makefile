# New ports collection makefile for:	med
# Date created:		Thu Jun 26 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	med
PORTVERSION=	2.1.5
PORTREVISION=	1
CATEGORIES=	french cad converters
MASTER_SITES=	http://www.code-aster.org/FICHIERS/
DISTNAME=	${PORTNAME}hdf-src-${PORTVERSION}-1.noarch
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modélisation et Échanges de Données

BUILD_DEPENDS=	${LOCALBASE}/lib/libhdf5.a:${PORTSDIR}/graphics/hdf5

EXTRACT_CMD=	${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-shared
CONFIGURE_ENV=	HDF5HOME=${LOCALBASE}
USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}.src

post-patch:
	@${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' \
		${WRKSRC}/config/commence.in

post-extract:
	@(cd ${WRKDIR} && \
	${TAR} xfz ${WRKDIR}/${PORTNAME}${PORTVERSION}.src.tar.gz)

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/doc/html ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
