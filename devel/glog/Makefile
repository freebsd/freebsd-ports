# New ports collection makefile for:	google-glog
# Date created:			        Oct 14, 2008
# Whom:				        Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glog
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A library of C++ classes for flexible logging

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		gflags.2:${PORTSDIR}/devel/gflags

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_GCC=	4.2+
PROJECTHOST=	google-glog

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} =="ia64" || ${ARCH} =="powerpc" || ${ARCH} =="sparc64"
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src-utilities.cc
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
