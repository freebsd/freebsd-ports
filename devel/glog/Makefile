# New ports collection makefile for:	google-glog
# Date created:			        Oct 14, 2008
# Whom:				        Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glog
DISTVERSION=	0.1.1
CATEGORIES=	devel
MASTER_SITES=	http://google-glog.googlecode.com/files/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A library of C++ classes for flexible logging

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} =="ia64"
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src-logging.cc \
		${FILESDIR}/extra-patch-src-raw_logging.cc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^docdir.*|docdir = ${DOCSDIR}|' ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e '/^install-data-am/,/^$$/ s,install-(dist_doc|dist_html|html)DATA,,g' \
	    ${WRKSRC}/Makefile.in
.endif

#regression-test:
#	cd ${WRKSRC}; ${MAKE} check

.include <bsd.port.post.mk>
