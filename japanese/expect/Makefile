# New ports collection makefile for:	expect
# Version required:	5.26
# Date created:		17 Oct 1997
# Whom:			taguchi
#
# $FreeBSD$
#

DISTNAME=	expect
PKGNAME=	ja-expect-5.30
CATEGORIES=	japanese lang tk80
MASTER_SITES=	http://expect.nist.gov/

MAINTAINER=	taguchi@tohoku.iij.ad.jp

LIB_DEPENDS=	tk80jp.1:${PORTSDIR}/japanese/tk80

WRKSRC=		${WRKDIR}/expect-5.30
USE_AUTOCONF=	yes
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
CONFIGURE_ARGS=	--enable-shared --with-tclconfig=${PREFIX}/lib/tcl8.0jp \
		--with-tkconfig=${PREFIX}/lib/tk8.0jp \
		--with-tclinclude=${PREFIX}/include/tcl8.0jp \
		--with-tkinclude=${PREFIX}/include/tk8.0jp

NO_MAN_INSTALL=	yes

.include <bsd.port.pre.mk>

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libexpect530jp.so.1.2 ${PREFIX}/lib/libexpect530jp.so
.endif

test:
	cd ${WRKSRC} && ${SETENV} PORTOBJFORMAT=${PORTOBJFORMAT} ${MAKE} test 

.include <bsd.port.post.mk>
