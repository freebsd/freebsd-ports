# New ports collection makefile for:	subversion
# Date created:				10 September 2001
# Whom:					rooneg@electricjellyfish.net
#
# $FreeBSD$

PORTNAME=	subversion
PORTVERSION=	r1302
CATEGORIES=	devel
MASTER_SITES=	http://www.tigris.org/files/15/48/

MAINTAINER=	rooneg@electricjellyfish.net

LIB_DEPENDS=	db4:${PORTSDIR}/databases/db4 \
		neon.18:${PORTSDIR}/www/neon

RUN_DEPENDS=	gdiff:${PORTSDIR}/textproc/diffutils \
		gpatch:${PORTSDIR}/devel/patch

BUILD_DEPENDS=	gdiff:${PORTSDIR}/textproc/diffutils \
		gpatch:${PORTSDIR}/devel/patch \

MAN1=		svn.1

WRKSRC=	${WRKDIR}/subversion-r1302
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --disable-shared --with-ssl --with-neon=${LOCALBASE}

post-extract:
	@${PERL} -pi -e 's/ldb/ldb4/g' ${WRKSRC}/configure
	@${PERL} -pi -e 's/external-install//g' ${WRKSRC}/Makefile.in
	@${RM} -r ${WRKSRC}/neon

post-configure:
	@${PERL} -pi -e 's/install-swig-py-lib//g' ${WRKSRC}/Makefile
	@${PERL} -pi -e 's/swig-py-lib//g' ${WRKSRC}/Makefile
	@${PERL} -pi -e 's/cd expat-lite ;/#/g' ${WRKSRC}/build-outputs.mk

.include <bsd.port.mk>
