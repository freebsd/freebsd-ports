# New ports collection makefile for:	subversion
# Date created:				10 September 2001
# Whom:					rooneg@electricjellyfish.net
#
# $FreeBSD$

PORTNAME=	subversion
PORTVERSION=	r1868	# 0.12.0
CATEGORIES=	devel
MASTER_SITES=	http://subversion.tigris.org/files/documents/15/196/

MAINTAINER=	rooneg@electricjellyfish.net

LIB_DEPENDS=	db4:${PORTSDIR}/databases/db4 \
		neon.19:${PORTSDIR}/www/neon \
		expat.2:${PORTSDIR}/textproc/expat2 \
		apr:${PORTSDIR}/devel/apr-devel
RUN_DEPENDS=	gdiff3:${PORTSDIR}/textproc/diffutils
BUILD_DEPENDS=	gdiff3:${PORTSDIR}/textproc/diffutils

MAN1=		svn.1

WRKSRC=	${WRKDIR}/subversion-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-ssl \
		--with-neon=${LOCALBASE} \
		--with-apr=${LOCALBASE} \
		--with-apr-util=${LOCALBASE}

post-extract:
	# work around libdb4's name.
	@${PERL} -pi -e 's/ldb/ldb4/g' ${WRKSRC}/configure

	# axe the neon, apr, and apr-util subdirs to keep svn's build process
	# from using them, since we're providing our own.
	@${RM} -r ${WRKSRC}/neon
	@${RM} -r ${WRKSRC}/apr
	@${RM} -r ${WRKSRC}/apr-util

post-configure:
	# make sure we don't install the swig stuff, even if it was found
	@${PERL} -pi -e 's/install-swig-py-lib//g' ${WRKSRC}/Makefile
	@${PERL} -pi -e 's/swig-py-lib//g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
