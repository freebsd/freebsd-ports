# New ports collection makefile for:	subversion
# Date created:				10 September 2001
# Whom:					rooneg@electricjellyfish.net
#
# $FreeBSD$

PORTNAME=	subversion
PORTVERSION=	r1587
CATEGORIES=	devel
MASTER_SITES=	http://www.tigris.org/files/15/38/

MAINTAINER=	rooneg@electricjellyfish.net

LIB_DEPENDS=	db4:${PORTSDIR}/databases/db4 \
		neon.19:${PORTSDIR}/www/neon \
		expat:${PORTSDIR}/textproc/expat \
		apr:${PORTSDIR}/devel/apr-devel
RUN_DEPENDS=	gdiff3:${PORTSDIR}/textproc/diffutils
BUILD_DEPENDS=	gdiff3:${PORTSDIR}/textproc/diffutils \
	 	python:${PORTSDIR}/lang/python

MAN1=		svn.1

WRKSRC=	${WRKDIR}/subversion-r1587
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
	# regenerate build-outputs.mk so we can use our installed expat,
	# rather than the expat-lite in svn's tree
	(cd ${WRKSRC} && ./gen-make.py -s build.conf)

	# make sure we don't install the swig stuff, even if it was found
	@${PERL} -pi -e 's/install-swig-py-lib//g' ${WRKSRC}/Makefile
	@${PERL} -pi -e 's/swig-py-lib//g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
