# ports collection makefile for:	MySQL++
# Date created:				20th July 2000
# Whom:					Miklos Niedermayer <mico@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	mysql++
PORTVERSION=	1.7.9
PORTREVISION=	2
CATEGORIES=	databases devel
MASTER_SITES=	ftp://ftp.free.fr/pub/MySQL/Downloads/mysql++/ \
		ftp://gd.tuwien.ac.at/db/mysql/Downloads/mysql++/ \
		ftp://mirror.sit.wisc.edu/mirrors/mysql/Downloads/mysql++/

MAINTAINER=	mico@bsd.hu
COMMENT=	Complex C++ API for MySQL

USE_MYSQL=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -D_FIX_FOR_BSD_ -Wno-deprecated"
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE} \
		--with-mysql-include=${LOCALBASE}/include/mysql/ \
		--with-mysql-lib=${LOCALBASE}/lib/mysql/
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 500035
PATCHFILES=	patch_gcc_3.3.gz
PATCH_SITES=	${MASTER_SITES}
PATCH_DIST_STRIP=-p1
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-sqlplusint-connection.cc
.endif

pre-configure:
	@${RM} ${WRKSRC}/examples/Makefile.in
	@${ECHO} "all:" >${WRKSRC}/examples/Makefile.in
	@${ECHO} "install:" >>${WRKSRC}/examples/Makefile.in

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/sqlplusint/.libs/libsqlplus.so.1 ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/sqlplusint/.libs/libsqlplus.a ${PREFIX}/lib
	@(cd ${PREFIX}/lib && ${RM} -f libsqlplus.so && ${LN} -s libsqlplus.so.1 libsqlplus.so)
	@ranlib ${PREFIX}/lib/libsqlplus.a
	@${MKDIR} ${PREFIX}/include/mysql
	@(cd ${WRKSRC}/sqlplusint/; \
	${INSTALL_DATA} mysql++ defs undef_short define_short *.hh ${PREFIX}/include/mysql)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/man-text/* ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/*.cc ${EXAMPLESDIR}
	@${INSTALL_DATA} ${FILESDIR}/README ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
