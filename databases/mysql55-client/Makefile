# ports collection makefile for:	MySQL-client
# Version required:			v3.22.23b
# Date created:				26 Jan 1998
# Whom:					Josh Tiefenbach <josh@ican.net>
#
# $Id: Makefile,v 1.56 1999/06/23 21:29:09 billf Exp $
#

DISTNAME=	mysql-3.22.23b-client
DISTFILES=	mysql-3.22.23b${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/mysql-3.22.23b
CATEGORIES=	databases
MASTER_SITES=	http://www.fh-wolfenbuettel.de/ftp/pub/database/mysql/Downloads/MySQL-3.22/ \
		ftp://ftp.digex.net/pub/packages/database/mysql/Downloads/MySQL-3.22/ \
		ftp://ftp.bse.bg/pub/Unix/database/MySQL/ \
		ftp://ftp.plig.net/pub/mysql/Downloads/MySQL-3.22/ \
		ftp://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/MySQL-3.22/

MAINTAINER=	dan@trinsec.com

Y2K=            http://www.tcx.se/Manual_chapter/manual_Introduction.html#Year_2000_compliance

MAN1=		mysql.1

USE_PERL5=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=/var/db/mysql \
		--without-perl \
		--without-debug \
		--without-readline \
		--without-bench \
		--without-server
CONFIGURE_ENV+=	PERL=${PERL} \
		PERL5=${PERL} \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		CXXFLAGS="${CFLAGS}" \
		CONFIGURE_ARGS="${CONFIGURE_ARGS}"

.include <bsd.port.pre.mk>

.if defined(NATIVE_THREADS) && ${OSVERSION} >= 300000
CONFIGURE_ARGS+=	--with-mit-threads=no
.else
CONFIGURE_ARGS+=	--with-mit-threads=yes
.endif

.if !defined(NATIVE_THREADS) && ${OSVERSION} >= 300000
pre-fetch:
	@${ECHO}
	@${ECHO} "You may set NATIVE_THREADS (make NATIVE_THREADS=yes)"
	@${ECHO} "to compile mysql with the native FreeBSD threads (libc_r)."
	@${ECHO} "Warning: There are still some bugs in libc_r which prevent"
	@${ECHO} "         'mysqladmin shutdown' from working properly and"
	@${ECHO} "         killing mysqld might not work."
	@${ECHO}
.elif defined(NATIVE_THREADS) && ${OSVERSION} >= 300000
pre-fetch:
	@${ECHO}
	@${ECHO} "Using native FreeBSD threads (libc_r)."
	@${ECHO}
.elif defined(NATIVE_THREADS) && ${OSVERSION} < 300000
pre-fetch:
	@${ECHO}
	@${ECHO} "Sorry, native FreeBSD threads (libc_r) in 2.2-branch"
	@${ECHO} "are still to buggy to use with mysql."
	@${ECHO} "Using mit-pthreads."
	@${ECHO}
.endif

pre-install:
.if !defined(PACKAGE_BUILDING)
	@ ${SETENV} ${MAKE_ENV} ${PERL5} ${SCRIPTDIR}/check_old_version
.endif

post-install:
	${MKDIR} ${PREFIX}/share/mysql/mysql

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mysql
.for doc in manual.html manual.ps manual_toc.html manual.txt manual.texi include.texi
	${INSTALL_DATA} ${WRKSRC}/Docs/${doc} ${PREFIX}/share/doc/mysql
.endfor
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info
	@install-info ${PREFIX}/info/mysql.info ${PREFIX}/info/dir
.endif

	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib/mysql

.include <bsd.port.post.mk>
