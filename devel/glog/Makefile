# New ports collection makefile for:	google-glog
# Date created:			        Oct 14, 2008
# Whom:				        Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glog
DISTVERSION=	0.2.1
CATEGORIES=	devel
MASTER_SITES=	http://google-glog.googlecode.com/files/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A library of C++ classes for flexible logging

LIB_DEPENDS+=	execinfo.1:${PORTSDIR}/devel/libexecinfo

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GCC=	4.2+

CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -lexecinfo"

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} =="ia64" || ${ARCH} =="sparc64"
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src-logging.cc \
		${FILESDIR}/extra-patch-src-utilities.cc
.endif

.if ${ARCH} == "amd64"
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-utilities.h
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
