# ports collection makefile for:	Berkeley DB
# Date created:				26 Jan 1998
# Whom:					Josh Tiefenbach <josh@ican.net>
#
# $FreeBSD$
#

PORTNAME=	db
PORTVERSION=	2.7.7
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/${PORTVERSION}/

MAINTAINER=	josh@ican.net

Y2K=		http://www.sleepycat.com/faq.html#A8

MANUAL_PACKAGE_BUILD=	incompatible with libc internal db calls
WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

INSTALLS_SHLIB=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS=		--enable-compat185 \
			--enable-dump185 --enable-cxx

post-install:
	${MKDIR} ${PREFIX}/share/examples/db2
	cd ${WRKSRC}/..; \
	    tar -cf - --exclude tags examples/ examples_cxx/ examples_java/ | \
	    ( cd ${PREFIX}/share/examples/db2; tar xf - )
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
