# ports collection makefile for:	Berkeley DB v4
# Date created:				16 August 2000
# Whom:					Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	db4
PORTVERSION=	4.0.14
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	http://download-uk.oracle.com/berkeley-db/ \
		http://download-west.oracle.com/berkeley-db/ \
		http://download-east.oracle.com/berkeley-db/
DISTNAME=	db-${PORTVERSION}
DIST_SUBDIR=	bdb

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	The Berkeley DB package, revision 4

WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS=	--enable-compat185 --enable-dump185 \
		--enable-cxx --enable-dynamic \
		--includedir=${PREFIX}/include/db4
USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install_docs
PORTDOCS=	*
.endif

# the db install_docs target installs an empty directory, kill it
# (it's not packaged and it's not needed):
.if !defined(NOPORTDOCS)
post-install:
	@${RMDIR} ${PREFIX}/share/doc/db4/ref/splash
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|-l?pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
