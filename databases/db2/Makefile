# ports collection makefile for:	Berkeley DB
# Date created:				26 Jan 1998
# Whom:					Josh Tiefenbach <josh@ican.net>
#
# $FreeBSD$
#

PORTNAME=	db2
PORTVERSION=	2.7.7
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/snapshot/
DISTNAME=	db-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Berkeley DB package, revision 2

WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

INSTALLS_SHLIB=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS=		--enable-compat185 \
			--enable-dump185 --enable-cxx

post-install:
	@-${RM} -fr ${PREFIX}/share/examples/db2
	${MKDIR} ${PREFIX}/share/examples/db2
	cd ${WRKSRC}/..; \
	    ${TAR} -cf - --exclude tags examples/ examples_cxx/ examples_java/. \
		| ( cd ${PREFIX}/share/examples/db2; ${TAR} xf - )
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Java support for ${PKGNAME} is *not* built by default, and requires that you"
	@${ECHO_MSG} "have a working copy of the JDK (v1.1) installed."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "To build java support, please read:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "${WRKDIR}/${DISTNAME}/java/README"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "and follow the directions therein."

.include <bsd.port.mk>
